/*
 * Zebra Interface interaction with the kernel using socket.
 * Copyright (C) 2022  NVIDIA CORPORATION & AFFILIATES
 *                     Stephen Worley
 *
 * This file is part of FRR.
 *
 * FRR is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * FRR is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with FRR; see the file COPYING.  If not, write to the Free
 * Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#include <zebra.h>

#ifndef HAVE_NETLINK

#include "lib_errors.h"

#include "zebra/rt.h"
#include "zebra/zebra_dplane.h"
#include "zebra/zebra_errors.h"

enum zebra_dplane_result kernel_intf_update(struct zebra_dplane_ctx *ctx)
{
	flog_err(EC_LIB_UNAVAILABLE, "%s not Implemented for this platform",
		 __func__);
	return ZEBRA_DPLANE_REQUEST_FAILURE;
}

enum zebra_dplane_result
kernel_intf_netconf_update(struct zebra_dplane_ctx *ctx)
{
	const char *ifname = dplane_ctx_get_ifname(ctx);
	enum dplane_netconf_status_e mpls_on = dplane_ctx_get_netconf_mpls(ctx);

	zlog_warn("%s:  Unable to set kernel mpls state for interface %s(%d)",
		  __func__, ifname, mpls_on);

	return ZEBRA_DPLANE_REQUEST_SUCCESS;
}
#endif
