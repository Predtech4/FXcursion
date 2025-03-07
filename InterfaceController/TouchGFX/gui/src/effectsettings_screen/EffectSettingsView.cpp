#include <gui/effectsettings_screen/EffectSettingsView.hpp>

EffectSettingsView::EffectSettingsView() {

}

void EffectSettingsView::setupScreen() {
	EffectSettingsViewBase::setupScreen();

	channelNum = presenter->getChannelNum();

	for (int i = 0; i < MAX_EFFECTS_NUM; i++) {
		menuItemInfoArray[i] = presenter->getFXchainItem(channelNum, i);
		effectPictograms[i]->setEffect(menuItemInfoArray[i]);
		if (menuItemInfoArray[i].effectNameID == T_EMPTYEFFECT)
			effectPictograms[i]->setVisible(false);
	}

	editingEffectNum = presenter->getChannelChainPosition(channelNum);
	selectedEffectNum = editingEffectNum;

	effectPictograms[selectedEffectNum]->select(true);
	effectPictograms[editingEffectNum]->edit(true);

	Unicode::snprintf(effectNameBuffer, EFFECTNAME_SIZE, "%s",
			touchgfx::TypedText(
					menuItemInfoArray[editingEffectNum].effectNameID).getText());

	const uint8_t io[10] = "";
	if (channelNum < 3) {
		strcpy((char*) io, "In ");
		char buf[2];
		sprintf(buf, "%d", channelNum + 1);
		strcat((char*) io, buf);
	} else {
		strcpy((char*) io, "Out ");
		char buf[2];
		sprintf(buf, "%d", (channelNum - 3) + 1);
		strcat((char*) io, buf);
	}

	Unicode::fromUTF8(io, chNum_textBuffer, CHNUM_TEXT_SIZE);

	audioAdapter.TxBuf[0] = REQUEST_PARAM;
	audioAdapter.TxBuf[1] = channelNum;
	audioAdapter.TxBuf[2] =
			(uint8_t) (menuItemInfoArray[editingEffectNum].effectNameID
					- T_CHORUSEFFECT);
	audioAdapter.TxBuf[3] = 0; // no matter, doesn't count
	audioAdapter.TxBuf[4] = 0; // no matter, doesn't count

	HAL_UART_Transmit_DMA(&huart2, audioAdapter.TxBuf, AUDIOUART_OUTBUF_SIZE);

	while (!audioAdapter.updateFlag);

	for (int i = 0; i < 4; i++) {

		customGauges[i]->setValue(audioAdapter.RxBuf[i]);

		switch (menuItemInfoArray[editingEffectNum].effectNameID) {
		case T_REVERBEFFECT:
			customGauges[i]->setParamName((TEXTS) (T_DECAYREVERBPARAM + i));
			break;
		default:
			customGauges[i]->setParamName((TEXTS) (T_RESOURCEID1 + i));
			break;
		}
	}

	audioAdapter.updateFlag = 0;
}

void EffectSettingsView::tearDownScreen() {
	EffectSettingsViewBase::tearDownScreen();
}

void EffectSettingsView::parameterChange(uint8_t id, int8_t scrollAmount) {

	customGauges[id]->changeValue(scrollAmount);

	audioAdapter.TxBuf[0] = CHANGE_PARAM;
	audioAdapter.TxBuf[1] = channelNum;
	audioAdapter.TxBuf[2] =
			(uint8_t) (menuItemInfoArray[editingEffectNum].effectNameID
					- T_CHORUSEFFECT);
	audioAdapter.TxBuf[3] = id;
	audioAdapter.TxBuf[4] = customGauges[id]->getValue();

	HAL_UART_Transmit_DMA(&huart2, audioAdapter.TxBuf, AUDIOUART_OUTBUF_SIZE);
}

void EffectSettingsView::encScroll_action(int8_t scrollAmount) {
	int8_t newPos = selectedEffectNum + scrollAmount;
	if (newPos >= 0 && newPos < MAX_EFFECTS_NUM
			&& effectPictograms[newPos]->isVisible()) {
		effectPictograms[selectedEffectNum]->select(false);
		selectedEffectNum = newPos;
		effectPictograms[selectedEffectNum]->select(true);
	}
}

void EffectSettingsView::btnYES_action(void) {
	if (selectedEffectNum != editingEffectNum) {

		effectPictograms[editingEffectNum]->edit(false);
		editingEffectNum = selectedEffectNum;
		effectPictograms[editingEffectNum]->edit(true);

		Unicode::snprintf(effectNameBuffer, EFFECTNAME_SIZE, "%s",
				touchgfx::TypedText(
						menuItemInfoArray[editingEffectNum].effectNameID).getText());

		audioAdapter.TxBuf[0] = REQUEST_PARAM;
		audioAdapter.TxBuf[1] = channelNum;
		audioAdapter.TxBuf[2] =
				(uint8_t) (menuItemInfoArray[editingEffectNum].effectNameID
						- T_CHORUSEFFECT);
		audioAdapter.TxBuf[3] = 0; // no matter, doesn't count
		audioAdapter.TxBuf[4] = 0; // no matter, doesn't count

		HAL_UART_Transmit_DMA(&huart2, audioAdapter.TxBuf, AUDIOUART_OUTBUF_SIZE);

		while(!audioAdapter.updateFlag);

		for (int i = 0; i < 4; i++) {

			customGauges[i]->setValue(audioAdapter.RxBuf[i]);

			switch (menuItemInfoArray[editingEffectNum].effectNameID) {
			case T_REVERBEFFECT:
				customGauges[i]->setParamName((TEXTS) (T_DECAYREVERBPARAM + i));
				break;
			default:
				customGauges[i]->setParamName((TEXTS) (T_RESOURCEID1 + i));
				break;
			}
		}

		audioAdapter.updateFlag = 0;

		invalidate();
	}
}

void EffectSettingsView::btnNO_action(void) {
	//TODO: change for COVER transition in TouchGFX Designer when switch to SDRAM
	application().gotoFXchainScreenBlockTransition();
}
