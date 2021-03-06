/*
 * Copyright (c) 2016 Axel Voitier
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef ZMQ_SUB_H_
#define ZMQ_SUB_H_

#include "zmtp.h"

void zmq_sub_init(zmq_socket_t *self);
PT_THREAD(zmq_sub_subscribe(zmq_socket_t *self, const char *topic));

#endif
