/*****************************************************************************
 * dr_40.h
 * Copyright (C) 2001-2011 VideoLAN
 *
 * Authors: rcorno (Nov 22, 2011)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *****************************************************************************/

/*!
 * \file <dr_40.h>
 * \author Corno Roberto <corno.roberto@gmail.com>
 * \brief Application interface for the DVB "network name"
 * descriptor decoder and generator.
 *
 * Application interface for the DVB "network name" descriptor
 * decoder and generator. This descriptor's definition can be found in
 * ETSI EN 300 468 section 6.2.27.
 */

#ifndef DR_40_H_
#define DR_40_H_

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * dvbpsi_dvb_network_name_dr_t
 *****************************************************************************/
/*!
 * \struct dvbpsi_dvb_network_name_dr_t
 * \brief "network name" descriptor structure.
 *
 * This structure is used to store a decoded "network name"
 * descriptor. (ETSI EN 300 468 section 6.2.27).
 */
/*!
 * \typedef struct dvbpsi_network_nameg_dr_s dvbpsi_dvb_network_name_dr_t
 * \brief dvbpsi_dvb_network_name_dr_t type definition.
 */
/*!
 * \struct dvbpsi_dvb_network_name_dr_s
 * \brief struct dvbpsi_dvb_network_name_dr_s definition @see dvbpsi_dvb_network_name_dr_t
 */
typedef struct dvbpsi_dvb_network_name_dr_s
{
  uint8_t      i_name_length;            /*!< length of the i_name_byte array */
  uint8_t      i_name_byte[255];         /*!< the name of the delivery system */

} dvbpsi_dvb_network_name_dr_t;

/*****************************************************************************
 * dvbpsi_decode_dvb_network_name_dr
 *****************************************************************************/
/*!
 * \fn dvbpsi_dvb_network_name_dr_t * dvbpsi_decode_dvb_network_name_dr(
                                        dvbpsi_descriptor_t * p_descriptor)
 * \brief "network name" descriptor decoder.
 * \param p_descriptor pointer to the descriptor structure
 * \return a pointer to a new "network name" descriptor structure
 * which contains the decoded data.
 */
dvbpsi_dvb_network_name_dr_t* dvbpsi_decode_dvb_network_name_dr(
                                        dvbpsi_descriptor_t * p_descriptor);


/*****************************************************************************
 * dvbpsi_gen_dvb_network_name_dr
 *****************************************************************************/
/*!
 * \fn dvbpsi_descriptor_t * dvbpsi_gen_dvb_network_name_dr(
                        dvbpsi_dvb_network_name_dr_t * p_decoded, bool b_duplicate)
 * \brief "network name" descriptor generator.
 * \param p_decoded pointer to a decoded "network name" descriptor
 * structure
 * \param b_duplicate if non zero then duplicate the p_decoded structure into
 * the descriptor
 * \return a pointer to a new descriptor structure which contains encoded data.
 */
dvbpsi_descriptor_t * dvbpsi_gen_dvb_network_name_dr(
                                        dvbpsi_dvb_network_name_dr_t * p_decoded,
                                        bool b_duplicate);

#ifdef DVBPSI_USE_DEPRECATED_DR_API
typedef dvbpsi_dvb_network_name_dr_t dvbpsi_network_name_dr_t ;

__attribute__((deprecated,unused)) static dvbpsi_network_name_dr_t* dvbpsi_DecodeNetworkNameDr (dvbpsi_descriptor_t *dr) {
    return dvbpsi_decode_dvb_network_name_dr (dr);
}

__attribute__((deprecated,unused)) static dvbpsi_descriptor_t* dvbpsi_GenNetworkNameDr (dvbpsi_network_name_dr_t* dr, bool dup) {
    return dvbpsi_gen_dvb_network_name_dr (dr, dup);
}
#endif

#ifdef __cplusplus
};
#endif

#else
#error "Multiple inclusions of dr_40.h"
#endif
