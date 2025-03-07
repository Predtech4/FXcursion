/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CUSTOMGAUGEBASE_HPP
#define CUSTOMGAUGEBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/canvas/Circle.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>

class CustomGaugeBase : public touchgfx::Container
{
public:
    CustomGaugeBase();
    virtual ~CustomGaugeBase();
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::TextAreaWithOneWildcard parameterName;
    touchgfx::Circle backgroundCircle;
    touchgfx::PainterRGB565 backgroundCirclePainter;
    touchgfx::Circle activeCircle;
    touchgfx::PainterRGB565 activeCirclePainter;

    /*
     * Wildcard Buffers
     */
    static const uint16_t PARAMETERNAME_SIZE = 20;
    touchgfx::Unicode::UnicodeChar parameterNameBuffer[PARAMETERNAME_SIZE];

private:

};

#endif // CUSTOMGAUGEBASE_HPP
