/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/SettingsItemBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

SettingsItemBase::SettingsItemBase()
{
    setWidth(90);
    setHeight(60);
    blackBox.setPosition(0, 0, 90, 40);
    blackBox.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    blackBox.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    blackBox.setBorderSize(5);
    add(blackBox);

    whiteBox.setPosition(0, 0, 90, 40);
    whiteBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    whiteBox.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    whiteBox.setBorderSize(5);
    add(whiteBox);

    orangeBox.setPosition(5, 5, 80, 30);
    orangeBox.setColor(touchgfx::Color::getColorFromRGB(255, 136, 0));
    orangeBox.setVisible(false);
    add(orangeBox);

    Text.setPosition(0, 7, 90, 26);
    Text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    Text.setLinespacing(0);
    TextBuffer[0] = 0;
    Text.setWildcard(TextBuffer);
    Text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_M188));
    add(Text);
}

SettingsItemBase::~SettingsItemBase()
{

}

void SettingsItemBase::initialize()
{

}
