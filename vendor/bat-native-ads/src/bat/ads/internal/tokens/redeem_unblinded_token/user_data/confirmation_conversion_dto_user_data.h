/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_TOKENS_REDEEM_UNBLINDED_TOKEN_USER_DATA_CONFIRMATION_CONVERSION_DTO_USER_DATA_H_
#define BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_TOKENS_REDEEM_UNBLINDED_TOKEN_USER_DATA_CONFIRMATION_CONVERSION_DTO_USER_DATA_H_

#include "base/values.h"
#include "bat/ads/internal/conversions/conversion_queue_item_info.h"

namespace ads {
namespace dto {
namespace user_data {

base::DictionaryValue GetConversion(
    const ConversionQueueItemList& conversion_queue_items);

}  // namespace user_data
}  // namespace dto
}  // namespace ads

#endif  // BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_TOKENS_REDEEM_UNBLINDED_TOKEN_USER_DATA_CONFIRMATION_CONVERSION_DTO_USER_DATA_H_
