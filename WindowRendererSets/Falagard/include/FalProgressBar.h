/************************************************************************
    filename:   FalProgressBar.h
    created:    Sat Jul 2 2005
    author:     Paul D Turner <paul@cegui.org.uk>
*************************************************************************/
/*************************************************************************
    Crazy Eddie's GUI System (http://www.cegui.org.uk)
    Copyright (C)2004 - 2005 Paul D Turner (paul@cegui.org.uk)
 
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.
 
    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.
 
    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*************************************************************************/
#ifndef _FalProgressBar_h_
#define _FalProgressBar_h_

#include "FalModule.h"
#include "FalProgressBarProperties.h"

#if defined(_MSC_VER)
#	pragma warning(push)
#	pragma warning(disable : 4251)
#endif

// Start of CEGUI namespace section
namespace CEGUI
{
    /*!
    \brief
        ProgressBar class for the FalagardBase module.

        This class requires LookNFeel to be assigned.  The LookNFeel should provide the following:

        States:
            - Enabled
            - Disabled
            - EnabledProgress
            - DisabledProgress

        Named Areas:
            - ProgressArea

        Property initialiser definitions:
            - VerticalProgress - boolean property.
              Determines whether the progress widget is horizontal or vertical.
              Default is horizontal.  Optional.

            - ReversedProgress - boolean property.
              Determines whether the progress grows in the opposite direction to
              what is considered 'usual'.  Set to "True" to have progress grow
              towards the left or bottom of the progress area.  Optional.
    */
    class FALAGARDBASE_API FalagardProgressBar : public WindowRenderer
    {
    public:
        static const utf8   TypeName[];     //! type name for this widget.

        /*!
        \brief
            Constructor
        */
        FalagardProgressBar(const String& type);

        bool isVertical() const;
        bool isReversed() const;

        void setVertical(bool setting);
        void setReversed(bool setting);

        void render();

    protected:
        // settings to make this class universal.
        bool d_vertical;    //!< True if progress bar operates on the vertical plane.
        bool d_reversed;    //!< True if progress grows in the opposite direction to usual (i.e. to the left / downwards).

        // property objects
        static FalagardProgressBarProperties::VerticalProgress d_verticalProperty;
        static FalagardProgressBarProperties::ReversedProgress d_reversedProperty;
    };

} // End of  CEGUI namespace section


#if defined(_MSC_VER)
#	pragma warning(pop)
#endif

#endif  // end of guard _FalProgressBar_h_
