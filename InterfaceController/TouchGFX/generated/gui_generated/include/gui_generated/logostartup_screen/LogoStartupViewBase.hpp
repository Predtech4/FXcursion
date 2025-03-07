/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef LOGOSTARTUPVIEWBASE_HPP
#define LOGOSTARTUPVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/logostartup_screen/LogoStartupPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <touchgfx/mixins/FadeAnimator.hpp>

class LogoStartupViewBase : public touchgfx::View<LogoStartupPresenter>
{
public:
    LogoStartupViewBase();
    virtual ~LogoStartupViewBase();
    virtual void setupScreen();
    virtual void afterTransition();

    /*
     * Custom Actions
     */
    virtual void action1()
    {
        // Override and implement this function in Screen1
    }
    

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box background;
    touchgfx::FadeAnimator< touchgfx::Image > rat_logo;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback < LogoStartupViewBase, const touchgfx::FadeAnimator<touchgfx::Image>& > logoFadeInteractionEndedCallback;

    /*
     * Callback Handler Declarations
     */
    void logoFadeInteractionEndedCallbackHandler(const touchgfx::FadeAnimator<touchgfx::Image>& comp);

};

#endif // LOGOSTARTUPVIEWBASE_HPP
