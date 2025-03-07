/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/EffectsListContainerBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

EffectsListContainerBase::EffectsListContainerBase() :
    updateItemCallback(this, &EffectsListContainerBase::updateItemCallbackHandler)
{
    setWidth(320);
    setHeight(240);
    darkeningBackground.setPosition(0, 0, 320, 240);
    darkeningBackground.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    darkeningBackground.setAlpha(149);
    add(darkeningBackground);

    subMenuWindow.setPosition(25, 0, 270, 240);
    subMenuWindow.setColor(touchgfx::Color::getColorFromRGB(36, 117, 58));
    subMenuWindow.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    subMenuWindow.setBorderSize(5);
    add(subMenuWindow);

    nameBox.setPosition(25, 0, 270, 40);
    nameBox.setColor(touchgfx::Color::getColorFromRGB(255, 238, 140));
    nameBox.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    nameBox.setBorderSize(5);
    add(nameBox);

    selectEffectText.setPosition(25, 7, 270, 25);
    selectEffectText.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    selectEffectText.setLinespacing(0);
    selectEffectText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_2REO));
    add(selectEffectText);

    scrollEffects.setPosition(45, 50, 230, 185);
    scrollEffects.setHorizontal(false);
    scrollEffects.setCircular(false);
    scrollEffects.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    scrollEffects.setSwipeAcceleration(10);
    scrollEffects.setDragAcceleration(10);
    scrollEffects.setNumberOfItems(10);
    scrollEffects.setSelectedItemOffset(0);
    scrollEffects.setSelectedItemExtraSize(0, 0);
    scrollEffects.setSelectedItemMargin(0, 0);
    scrollEffects.setDrawableSize(40, 0);
    scrollEffects.setDrawables(scrollEffectsListItems, updateItemCallback,
    
                          scrollEffectsSelectedListItems, updateItemCallback);
    scrollEffects.animateToItem(0, 0);
    add(scrollEffects);
}

EffectsListContainerBase::~EffectsListContainerBase()
{

}

void EffectsListContainerBase::initialize()
{
    scrollEffects.initialize();
    for (int i = 0; i < scrollEffectsListItems.getNumberOfDrawables(); i++)
    {
        scrollEffectsListItems[i].initialize();
    }
    for (int i = 0; i < scrollEffectsSelectedListItems.getNumberOfDrawables(); i++)
    {
        scrollEffectsSelectedListItems[i].initialize();
    }
}

void EffectsListContainerBase::updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex)
{
    if (items == &scrollEffectsListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        EffectListItem* cc = (EffectListItem*)d;
        scrollEffectsUpdateItem(*cc, itemIndex);
    }
    if (items == &scrollEffectsSelectedListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        EffectListItemSelected* cc = (EffectListItemSelected*)d;
        scrollEffectsUpdateCenterItem(*cc, itemIndex);
    }
}
