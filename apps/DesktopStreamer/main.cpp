/*********************************************************************/
/* Copyright (c) 2011-2012, The University of Texas at Austin.       */
/* Copyright (c) 2013-2017, EPFL/Blue Brain Project                  */
/*                          Raphael Dumusc <raphael.dumusc@epfl.ch>  */
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

#include "MainWindow.h"

#include <deflect/version.h>

#include <QCommandLineParser>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QApplication::setApplicationVersion(
        QString::fromStdString(deflect::Version::getString()));

    QCommandLineParser parser;
    parser.setApplicationDescription("Stream your desktop to a remote host");
    QCommandLineOption streamEnabledOption(QStringList() << "e"
                                                         << "enable",
                                           "Enable streaming on startup.");
    parser.addOption(streamEnabledOption);
    QCommandLineOption advancedOption(QStringList() << "a"
                                                    << "advanced",
                                      "Show advanced settings.");
    parser.addOption(advancedOption);
    parser.addPositionalArgument("host", "Default host to stream to.");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.process(app);

    const auto posArgs = parser.positionalArguments();
    const auto host = posArgs.isEmpty() ? QString() : posArgs.at(0);
    const auto enable = parser.isSet(streamEnabledOption);
    const auto advanced = parser.isSet(advancedOption);

    Q_INIT_RESOURCE(resources);

    MainWindow mainWindow{{host, enable, advanced}};
    mainWindow.show();

    // enter Qt event loop
    return app.exec();
}
