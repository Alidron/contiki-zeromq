#ifndef ZMTP_H_
#define ZMTP_H_

#include "zmq.h"

#define CONNECTION_VALIDATED_SIGNATURE 0x01
#define CONNECTION_VALIDATED_VERSION 0x02
#define CONNECTION_VALIDATED_GREETING 0x04
#define CONNECTION_VALIDATED_READY 0x08
#define CONNECTION_VALIDATED (CONNECTION_VALIDATED_SIGNATURE | \
                              CONNECTION_VALIDATED_VERSION   | \
                              CONNECTION_VALIDATED_GREETING  | \
                              CONNECTION_VALIDATED_READY)

int zmtp_connection_add_in_msg(zmtp_connection_t *self, zmq_msg_t *msg);
zmq_msg_t *zmtp_connection_pop_in_msg(zmtp_connection_t *self);
int zmtp_connection_add_out_msg(zmtp_connection_t *self, zmq_msg_t *msg);
zmq_msg_t *zmtp_connection_pop_out_msg(zmtp_connection_t *self);

zmtp_connection_t *zmtp_connection_new();
void zmtp_connection_destroy (zmtp_connection_t **self_p);
void zmtp_connection_init(zmtp_connection_t *self);
int zmtp_connection_tcp_connect (zmtp_connection_t *self);
int zmtp_connection_tcp_listen (zmtp_connection_t *self);

void zmtp_init();
int zmtp_listen(zmtp_channel_t *chan, unsigned short port);

zmtp_channel_t *zmtp_channel_new (zmq_socket_type_t socket_type, struct process *in_p, struct process *out_p);
void zmtp_channel_destroy (zmtp_channel_t **self_p);
void zmtp_channel_init(zmtp_channel_t *self, zmq_socket_type_t socket_type, struct process *in_p, struct process *out_p);

int zmtp_process_post(process_event_t ev, process_data_t data);

#endif
