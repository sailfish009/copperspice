/***********************************************************************
*
* Copyright (c) 2012-2017 Barbara Geller
* Copyright (c) 2012-2017 Ansel Sermersheim
* Copyright (c) 2012-2016 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
*
* This file is part of CopperSpice.
*
* CopperSpice is free software. You can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* <http://www.gnu.org/licenses/>.
*
***********************************************************************/

/********************************************************
**  This file is part of the KDE project.
********************************************************/

#include "backend.h"
#include "audiooutput.h"
#include "mediaobject.h"

#include <QtCore/QSettings>
#include <QtCore/QSet>
#include <QtCore/QVariant>
#include <QtCore/QStringList>

#include <QtCore/QtPlugin>

QT_BEGIN_NAMESPACE

// export as Qt/KDE factory as required

Q_EXPORT_PLUGIN2(phonon_waveout, Phonon::WaveOut::Backend);

namespace Phonon
{
    namespace WaveOut
    {

        Backend::Backend(QObject *parent, const QVariantList &)
            : QObject(parent)
        {
        }

        Backend::~Backend()
        {
        }

        QObject *Backend::createObject(BackendInterface::Class c, QObject *parent, const QList<QVariant> &args)
        {
            Q_UNUSED(args);
            switch (c)
            {
            case MediaObjectClass:
                return new MediaObject(parent);
            case AudioOutputClass:
                return new AudioOutput(this, parent);
            default:
                return 0;
            }
        }

        bool Backend::supportsVideo() const
        {
            return false;
        }

        QStringList Backend::availableMimeTypes() const
        {
            QStringList ret;
            return ret;
        }


        QList<int> Backend::objectDescriptionIndexes(Phonon::ObjectDescriptionType type) const
        {
            QList<int> r;
            if (type == Phonon::AudioOutputDeviceType)
              r.append(0);
            return r;
        }

        QHash<QByteArray, QVariant> Backend::objectDescriptionProperties(Phonon::ObjectDescriptionType type, int index) const
        {
            Q_UNUSED(index);
            QHash<QByteArray, QVariant> r;
            if (type == Phonon::AudioOutputDeviceType) 
                r["name"] = QLatin1String("default audio device");
            return r;
        }


         bool Backend::connectNodes(QObject *node1, QObject *node2)
         {
             MediaObject *mediaObject = qobject_cast<MediaObject*> (node1);
             AudioOutput *audioOutput = qobject_cast<AudioOutput*> (node2);

             if (mediaObject && audioOutput)
                 mediaObject->setAudioOutput(audioOutput);
             return true;
         }

         bool Backend::disconnectNodes(QObject *node1, QObject *node2)
         {
             Q_UNUSED(node1);
             Q_UNUSED(node2);
             return true;
         }

         //transaction management
         bool Backend::startConnectionChange(QSet<QObject *>)
         {
             return true;
         }

         bool Backend::endConnectionChange(QSet<QObject *>)
         {
             return true;
         }

    }
}

QT_END_NAMESPACE

