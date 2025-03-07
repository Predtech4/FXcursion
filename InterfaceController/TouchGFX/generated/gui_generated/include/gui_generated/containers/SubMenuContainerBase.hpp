/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SUBMENUCONTAINERBASE_HPP
#define SUBMENUCONTAINERBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/containers/ListLayout.hpp>
#include <gui/containers/SubMenuItem.hpp>
#include <gui/containers/ModalWindowDelete.hpp>

class SubMenuContainerBase : public touchgfx::Container
{
public:
    SubMenuContainerBase();
    virtual ~SubMenuContainerBase();
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box darkeningBackground;
    touchgfx::BoxWithBorder subMenuWindow;
    touchgfx::ListLayout listLayout;
    SubMenuItem subMenuItem0;
    SubMenuItem subMenuItem1;
    SubMenuItem subMenuItem2;
    SubMenuItem subMenuItem3;
    ModalWindowDelete modalWindowDelete;

private:

};

#endif // SUBMENUCONTAINERBASE_HPP
