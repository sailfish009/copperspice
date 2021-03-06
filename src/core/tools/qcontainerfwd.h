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

#ifndef QCONTAINERFWD_H
#define QCONTAINERFWD_H

#include <qglobal.h>

QT_BEGIN_NAMESPACE

template <class Key, class T> class QCache;
template <class Key, class T> class QHash;

template <class T> class QList;
template <class T> class QLinkedList;

template <class Key> class qMapCompare;
template <class Key, class T, class Compare = qMapCompare<Key>> class QMap;
template <class Key, class T, class Compare = qMapCompare<Key>> class QMultiMap;

template <class Key, class T> class QMultiHash;
template <class T1, class T2> struct QPair;
template <class T> class QQueue;
template <class T> class QSet;
template <class T> class QStack;
template<class T, int Prealloc = 256> class QVarLengthArray;
template <class T> class QVector;

QT_END_NAMESPACE

#endif // QCONTAINERFWD_H
