/*********************************************************************/
/* Copyright (c) 2014-2017, EPFL/Blue Brain Project                  */
/*                          Raphael Dumusc <raphael.dumusc@epfl.ch>  */
/*                          Daniel.Nachbaur@epfl.ch                  */
/* All rights reserved.                                              */
/*                                                                   */
/* Redistribution and use in source and binary forms, with or        */
/* without modification, are permitted provided that the following   */
/* conditions are met:                                               */
/*                                                                   */
/*   1. Redistributions of source code must retain the above         */
/*      copyright notice, this list of conditions and the following  */
/*      disclaimer.                                                  */
/*                                                                   */
/*   2. Redistributions in binary form must reproduce the above      */
/*      copyright notice, this list of conditions and the following  */
/*      disclaimer in the documentation and/or other materials       */
/*      provided with the distribution.                              */
/*                                                                   */
/*    THIS  SOFTWARE  IS  PROVIDED  BY  THE  ECOLE  POLYTECHNIQUE    */
/*    FEDERALE DE LAUSANNE  ''AS IS''  AND ANY EXPRESS OR IMPLIED    */
/*    WARRANTIES, INCLUDING, BUT  NOT  LIMITED  TO,  THE  IMPLIED    */
/*    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  A PARTICULAR    */
/*    PURPOSE  ARE  DISCLAIMED.  IN  NO  EVENT  SHALL  THE  ECOLE    */
/*    POLYTECHNIQUE  FEDERALE  DE  LAUSANNE  OR  CONTRIBUTORS  BE    */
/*    LIABLE  FOR  ANY  DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,    */
/*    EXEMPLARY,  OR  CONSEQUENTIAL  DAMAGES  (INCLUDING, BUT NOT    */
/*    LIMITED TO,  PROCUREMENT  OF  SUBSTITUTE GOODS OR SERVICES;    */
/*    LOSS OF USE, DATA, OR  PROFITS;  OR  BUSINESS INTERRUPTION)    */
/*    HOWEVER CAUSED AND  ON ANY THEORY OF LIABILITY,  WHETHER IN    */
/*    CONTRACT, STRICT LIABILITY,  OR TORT  (INCLUDING NEGLIGENCE    */
/*    OR OTHERWISE) ARISING  IN ANY WAY  OUT OF  THE USE OF  THIS    */
/*    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   */
/*                                                                   */
/* The views and conclusions contained in the software and           */
/* documentation are those of the authors and should not be          */
/* interpreted as representing official policies, either expressed   */
/* or implied, of Ecole polytechnique federale de Lausanne.          */
/*********************************************************************/

#include "Event.h"
#include "Segment.h"
#include "SizeHints.h"
#include "server/Tile.h"
#include "server/types.h"
#include "types.h"

#include <QMetaType>

namespace deflect
{
/**
 * Register types for use in Qt signals/slots
 */
struct MetaTypeRegistration
{
    MetaTypeRegistration()
    {
        qRegisterMetaType<size_t>("size_t");
        qRegisterMetaType<deflect::Segment>("deflect::Segment");
        qRegisterMetaType<deflect::SizeHints>("deflect::SizeHints");
        qRegisterMetaType<deflect::Event>("deflect::Event");
        qRegisterMetaType<deflect::View>("deflect::View");
        qRegisterMetaType<deflect::server::BoolPromisePtr>(
            "deflect::server::BoolPromisePtr");
        qRegisterMetaType<deflect::server::FramePtr>(
            "deflect::server::FramePtr");
        qRegisterMetaType<deflect::server::Tile>("deflect::server::Tile");
    }
};

// Static instance to register types during library static initialisation phase
static MetaTypeRegistration staticInstance;
}
