/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/WiringChangeBoxBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

WiringChangeBoxBase::WiringChangeBoxBase()
{
    setWidth(320);
    setHeight(50);
    boxWithBorder1.setPosition(0, 0, 320, 50);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(196, 29, 29));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorder1.setBorderSize(5);
    add(boxWithBorder1);

    Text.setPosition(0, 13, 320, 25);
    Text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Text.setLinespacing(0);
    TextBuffer1[0] = 0;
    Text.setWildcard1(TextBuffer1);
    TextBuffer1[0] = 0;
    Text.setWildcard2(TextBuffer2);
    Text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_4KK0));
    add(Text);
}

WiringChangeBoxBase::~WiringChangeBoxBase()
{

}

void WiringChangeBoxBase::initialize()
{

}
