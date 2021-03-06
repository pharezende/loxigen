:: # Copyright 2013, Big Switch Networks, Inc.
:: #
:: # LoxiGen is licensed under the Eclipse Public License, version 1.0 (EPL), with
:: # the following special exception:
:: #
:: # LOXI Exception
:: #
:: # As a special exception to the terms of the EPL, you may distribute libraries
:: # generated by LoxiGen (LoxiGen Libraries) under the terms of your choice, provided
:: # that copyright and licensing notices generated by LoxiGen are not altered or removed
:: # from the LoxiGen Libraries and the notice provided below is (i) included in
:: # the LoxiGen Libraries, if distributed in source code form and (ii) included in any
:: # documentation for the LoxiGen Libraries, if distributed in binary form.
:: #
:: # Notice: "Copyright 2013, Big Switch Networks, Inc. This library was generated by the LoxiGen Compiler."
:: #
:: # You may not use this file except in compliance with the EPL or LOXI Exception. You may obtain
:: # a copy of the EPL at:
:: #
:: # http://www.eclipse.org/legal/epl-v10.html
:: #
:: # Unless required by applicable law or agreed to in writing, software
:: # distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
:: # WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
:: # EPL for the specific language governing permissions and limitations
:: # under the EPL.
::
:: include('_copyright.c')

/**
 * @file of_doc.h
 * @brief Documentation of sample functions
 *
 * This file is for documentation purposes only
 *
 * Once the code is in a working state, this documentation will be 
 * transfered to the actual source files
 *
 * The functions documented here are simple templates for accessors that
 * are used for all accessor members of LOCI objects.  Data types are
 * divided into:
 *
 * @li @c scalar Things like uint8_t, uint16_t, of_mac_addr_t as well as
 * fixed length strings
 * @li @c octets Arbitrary length strings of binary data
 * @li @c composite Data members which are structures
 * @li @c list The list abstraction for data members
 * @li @c list_element An element of a list (usually a composite object)
 *
 * List elements get special treatment for iterating across a list or 
 * appending new entries to the list.  All others have 'set' and 'get'
 * operations.  
 *
 * Scalars operations are "stateless" in that they simply
 * update the underlying data or return that data.  
 *
 * Composites and list members update structures to point to the
 * underlying data.  As a result, care must be taken that objects are
 * not freed when linked composite or list members remain referring to
 * the underlying data structure.  Currently: Note that reference
 * counting won't solve this with the current approach as the
 * referring objects may be automatic and not subject to alloc/free
 * operations.
 */



/**
 * Generic documentation for scalar get methods
 * @param obj The object being accessed
 * @param value A pointer to a scalar instance of the proper type
 * @return OF_ERROR_XXX
 *
 * Accesses the underlying wire buffer at the appropriate offset to
 * retrieve and convert the value, placing the result in *value.
 *
 * Examples of scalar types include:
 * @li uint8_t
 * @li uint16_t
 * @li uint32_t
 * @li uint64_t
 * @li of_mac_addr_t
 *
 * Examples calls include:
 * @li rv = of_port_status_reason_get(obj, &reason)
 * @li rv = of_table_mod_config_get(obj, &config)
 *
 * An object instance can call directly as:
 * @li rv = obj->reason_get(obj, &reason);    obj is an of_table_mod_t *
 * @li rv = obj->config_get(obj, &config);    obj is an of_table_mod_t *
 */
extern int of_object_scalar_member_get(of_object_t *obj, uint32_t *value);

/**
 * Generic documentation for scalar set methods
 * @param obj The object being accessed
 * @param value Call by value parameter with the value to set
 * @return OF_ERROR_XXX
 *
 * Converts value to the proper wire representation and writes it to
 * the underlying wire buffer at the appropriate offset.
 */
extern int of_object_scalar_member_set(of_object_t *obj, uint32_t value);

/**
 * Generic documentation for an octets data get method
 * @param obj The object being accessed
 * @param value A pointer to an of_octets_t structure to be filled out 
 * @return OF_ERROR_XXX
 *
 * NOTE: 
 * Sets *bytes to the number of bytes in the octet string.
 */
extern int of_object_octets_member_data_get(of_object_t *obj, of_octets_t *value);

/**
 * Generic documentation for an octets data set method
 * @param obj The object being accessed
 * @param value Pointer to an of_octets_t structure pointing to memory from
 * which data will be copied to wire buffer
 * @return OF_ERROR_XXX
 *
 * Copies data from the memory pointed to by value into the underlying 
 * wire buffer, extending the buffer if necessary.  The length of obj 
 * is updated.
 *
 * If the length of obj changes (because the existing octets instance is of
 * a different length) its internal length accessor is called to update
 * anything tracking its length.  This may call the object's parent
 * length accessor with the update.
 */
extern int of_object_octets_member_data_set(of_object_t *obj, of_octets_t *value);

/**
 * Generic documentation for an octets pointer get method
 * @param obj The object being accessed
 * @param value Pointer to an of_octets_t structure to be initialized
 * @return OF_ERROR_XXX
 *
 * Set the octets object *value to point to the underlying data buffer.  The
 * length member of *value is set as well.
 *
 * The result should be treated as READ ONLY information as modifying
 * the buffer could cause corruption of the underlying LOCI object.
 * To change the value (especially the length) of an octets data member,
 * allocate and set a memory buffer and use the octets_member_data_set 
 * function.
 */
extern int of_object_octets_member_ptr_get(of_object_t *obj, of_octets_t *value);

/**
 * Generic documentation for a composite sub-object get method
 * @param obj The object being accessed
 * @param value Pointer to an object (the sub-object) of the proper type
 * @return OF_ERROR_XXX
 *
 * A composite is a structure with multiple components.  On a 'get'
 * operation, a pointer (value) to an unused instance of the appropriate 
 * type is passed to this routine.  That instance is intialized with the
 * proper accessor functions for the sub-object type and the wire object
 * is set up to point to obj's wire buffer at the appropriate offset.
 *
 * If changes are made to the sub-object (*value) and those changes
 * affect the length, then the corresponding composite_set must be
 * called to commit those changes to the parent.
 */
extern int of_object_composite_member_get(of_object_t *obj, 
                                          of_object_t *value);

/**
 * Generic documentation for a composite sub-object set method
 * @param obj The object being accessed
 * @param value Pointer to an object (the sub-object) of the proper type
 * @return OF_ERROR_XXX
 *
 * A composite is a structure with multiple components.  On a 'set'
 * operation, a pointer (value) to an instance of the appropriate type
 * is passed to this routine.  
 *
 * If the parent (obj) and the child (value) point to the same underlying
 * wire object, then the changes to the underlying buffer are already
 * recorded.
 *
 * Otherwise, any existing value of the sub-object is replaced
 * by copying the wire buffer contents from value's wire buffer to obj's
 * wire buffer at the appropriate offset.
 *
 * In either case, the length of the parent will be updated if it changes.
 */
extern int of_object_composite_member_set(of_object_t *obj, 
                                          of_object_t *value);

/**
 * Generic documentation for a list sub-object get method
 * @param obj The object being accessed
 * @param value Pointer to an object (the list sub-object)
 * @return OF_ERROR_XXX
 *
 * A list is an array of instances of objects of a common (possibly
 * polymorphic) type.  On a 'get' operation, a pointer (value) to an
 *  unused instance of the appropriate list type is passed to this
 * routine.  That instance is intialized with the proper accessor
 * functions for the list type and the wire object is set up to point
 * to obj's wire buffer at the appropriate offset.
 *
 * Currently, the list object returned by a 'get' operation should not
 * be altered, although changes that do not affect the length of
 * sub-objects will work.
 *
 * Rather, lists should either be cleared and set from completely new
 * instances using 'list_set', or they may be built using the append
 * operations described below.
 *
 * @sa of_object_list_append_bind
 * @sa of_object_list_append
 */
extern int of_object_list_member_get(of_object_t *obj, 
                                     of_list_object_t *value);

/**
 * Generic documentation for a list entry first call
 * @param obj The list object being accessed
 * @param value Pointer to a generic list entry instance
 * @return OF_ERROR_RANGE if the list is empty
 *
 * A list is an array of instances of objects of a common (possibly
 * polymorphic) type.  
 *
 * This routine is intended for iterating through a list for
 * reading.  Normally a 'get' operation will be done on the parent
 * of the list to retrieve (a pointer to) the list, and then this routine
 * will be called to set up a generic entry representing the first 
 * element of the list.
 *
 * @sa of_object_list_entry_next
 */
extern int of_object_list_entry_first(of_list_object_t *obj, 
                                      of_object_t *value);

/**
 * Generic documentation for a list entry next call
 * @param obj The list object being accessed
 * @param value Pointer to a generic list entry instance
 * @return OF_ERROR_RANGE if the value already points to the last item 
 * in the list

 * A list is an array of instances of objects of a common (possibly
 * polymorphic) type.  
 *
 * The corresponding list_entry_first must be called on the pair of
 * parameters initially.  There after, this routine will advance the
 * pointers in the wire object of value to the subsequent entry in the
 * list.
 *
 * Changes should not be made to list items using these routines,
 * although 'set' operations which do not change the length of the
 * instance will work.
 *
 * @sa of_object_list_entry_first
 */
extern int of_object_list_entry_next(of_list_object_t *obj, 
                                     of_object_t *value);

/**
 * Generic documentation for a list append bind function
 * @param obj The list object being accessed
 * @param value Pointer to a generic list entry instance
 * @return OF_ERROR_XXX
 *
 * A list is an array of instances of objects of a common (possibly
 * polymorphic) type.
 *
 * This function prepares the list for the process of appending an
 * item to its tail.  The parameter value is a pointer to a generic
 * list entry instance.  Its wire buffer is bound to that of the list
 * at the end of the list.  The length of the list is updated according
 * to the current value setting which must be accurate.
 *
 * Note that since the child has not been bound to a buffer, no
 * values have been properly recorded for the object; they must
 * be set after this _bind call.
 *
 * @sa of_object_list_entry_append
 */
extern int of_object_list_entry_append_bind(of_list_object_t *obj, 
                                            of_object_t *value);

/**
 * Generic documentation for a list append function
 * @param obj The list object being accessed
 * @param value Pointer to a list object to be appended
 * @return OF_ERROR_XXX
 *
 * A list is an array of instances of objects of a common (possibly
 * polymorphic) type.
 *
 * This function takes a fully formed list entry, value, and copies
 * that value to the end of the list.  No object ownership changes
 * with this call.
 *
 * @sa of_object_list_entry_append_bind
 */
extern int of_object_list_entry_append(of_list_object_t *obj, 
                                       of_object_t *value);

/* This is from loci.h */

/**
 * Inheritance super class for of_queue_prop
 *
 * This class is the union of of_queue_prop classes.  You can refer
 * to it untyped by refering to the member 'header' whose structure
 * is common across all sub-classes.
 */

union of_queue_prop_u {
    of_queue_prop_header_t header; /* Generic instance */
    of_queue_prop_min_rate_t min_rate;
    of_queue_prop_max_rate_t max_rate;
    of_queue_prop_experimenter_t experimenter;
};

/**
 * Inheritance super class for of_action
 *
 * This class is the union of of_action classes.  You can refer
 * to it untyped by refering to the member 'header' whose structure
 * is common across all sub-classes.
 */

union of_action_u {
    of_action_header_t header; /* Generic instance */
    of_action_copy_ttl_out_t copy_ttl_out;
    of_action_set_mpls_tc_t set_mpls_tc;
    of_action_set_field_t set_field;
    of_action_set_nw_tos_t set_nw_tos;
    of_action_dec_mpls_ttl_t dec_mpls_ttl;
    of_action_set_nw_dst_t set_nw_dst;
    of_action_set_mpls_label_t set_mpls_label;
    of_action_group_t group;
    of_action_set_nw_src_t set_nw_src;
    of_action_set_vlan_vid_t set_vlan_vid;
    of_action_set_mpls_ttl_t set_mpls_ttl;
    of_action_pop_vlan_t pop_vlan;
    of_action_set_tp_dst_t set_tp_dst;
    of_action_pop_mpls_t pop_mpls;
    of_action_push_vlan_t push_vlan;
    of_action_set_vlan_pcp_t set_vlan_pcp;
    of_action_enqueue_t enqueue;
    of_action_set_tp_src_t set_tp_src;
    of_action_experimenter_t experimenter;
    of_action_set_nw_ttl_t set_nw_ttl;
    of_action_copy_ttl_in_t copy_ttl_in;
    of_action_set_nw_ecn_t set_nw_ecn;
    of_action_strip_vlan_t strip_vlan;
    of_action_set_dl_dst_t set_dl_dst;
    of_action_push_mpls_t push_mpls;
    of_action_dec_nw_ttl_t dec_nw_ttl;
    of_action_set_dl_src_t set_dl_src;
    of_action_set_queue_t set_queue;
    of_action_output_t output;
};

/**
 * Inheritance super class for of_instruction
 *
 * This class is the union of of_instruction classes.  You can refer
 * to it untyped by refering to the member 'header' whose structure
 * is common across all sub-classes.
 */

union of_instruction_u {
    of_instruction_header_t header; /* Generic instance */
    of_instruction_clear_actions_t clear_actions;
    of_instruction_write_actions_t write_actions;
    of_instruction_goto_table_t goto_table;
    of_instruction_apply_actions_t apply_actions;
    of_instruction_experimenter_t experimenter;
    of_instruction_write_metadata_t write_metadata;
};

/**
 * Inheritance super class for of_oxm
 *
 * This class is the union of of_oxm classes.  You can refer
 * to it untyped by refering to the member 'header' whose structure
 * is common across all sub-classes.
 */

union of_oxm_u {
    of_oxm_header_t header; /* Generic instance */
    of_oxm_ipv6_flabel_t ipv6_flabel;
    of_oxm_ipv6_dst_masked_t ipv6_dst_masked;
    of_oxm_vlan_pcp_t vlan_pcp;
    of_oxm_ipv4_src_t ipv4_src;
    of_oxm_ipv6_dst_t ipv6_dst;
    of_oxm_arp_tpa_t arp_tpa;
    of_oxm_icmpv6_type_t icmpv6_type;
    of_oxm_arp_sha_t arp_sha;
    of_oxm_ipv6_src_t ipv6_src;
    of_oxm_sctp_src_t sctp_src;
    of_oxm_quic_stream_id_t quic_stream_id;
    of_oxm_icmpv6_code_t icmpv6_code;
    of_oxm_metadata_masked_t metadata_masked;
    of_oxm_eth_src_masked_t eth_src_masked;
    of_oxm_eth_dst_t eth_dst;
    of_oxm_ipv6_nd_sll_t ipv6_nd_sll;
    of_oxm_mpls_tc_t mpls_tc;
    of_oxm_arp_op_t arp_op;
    of_oxm_vlan_vid_masked_t vlan_vid_masked;
    of_oxm_eth_type_t eth_type;
    of_oxm_in_phy_port_t in_phy_port;
    of_oxm_vlan_vid_t vlan_vid;
    of_oxm_arp_tha_t arp_tha;
    of_oxm_arp_tpa_masked_t arp_tpa_masked;
    of_oxm_in_port_t in_port;
    of_oxm_ip_dscp_t ip_dscp;
    of_oxm_sctp_dst_t sctp_dst;
    of_oxm_icmpv4_code_t icmpv4_code;
    of_oxm_eth_dst_masked_t eth_dst_masked;
    of_oxm_tcp_src_t tcp_src;
    of_oxm_ip_ecn_t ip_ecn;
    of_oxm_ipv6_src_masked_t ipv6_src_masked;
    of_oxm_ipv4_src_masked_t ipv4_src_masked;
    of_oxm_udp_dst_t udp_dst;
    of_oxm_arp_spa_t arp_spa;
    of_oxm_ipv6_nd_target_t ipv6_nd_target;
    of_oxm_ipv4_dst_t ipv4_dst;
    of_oxm_ipv4_dst_masked_t ipv4_dst_masked;
    of_oxm_eth_src_t eth_src;
    of_oxm_udp_src_t udp_src;
    of_oxm_ipv6_nd_tll_t ipv6_nd_tll;
    of_oxm_icmpv4_type_t icmpv4_type;
    of_oxm_mpls_label_t mpls_label;
    of_oxm_tcp_dst_t tcp_dst;
    of_oxm_ip_proto_t ip_proto;
    of_oxm_metadata_t metadata;
    of_oxm_arp_spa_masked_t arp_spa_masked;
};

