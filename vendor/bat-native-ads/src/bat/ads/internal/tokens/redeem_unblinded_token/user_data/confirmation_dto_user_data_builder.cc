/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/tokens/redeem_unblinded_token/user_data/confirmation_dto_user_data_builder.h"

#include "base/base64url.h"
#include "bat/ads/internal/account/confirmations/confirmation_info.h"

namespace ads {
namespace dto {
namespace user_data {

void Build(const ConfirmationInfo& confirmation, Callback callback) {
  base::Value user_data(base::Value::Type::DICTIONARY);

  const base::DictionaryValue platform_user_data = GetPlatform();
  user_data.Append(platform_user_data);

  const base::DictionaryValue build_channel_user_data = GetBuildChannel();
  user_data.Append(build_channel_user_data);

  const base::DictionaryValue locale_user_data = GetLocale();
  user_data.Append(locale_user_data);

  const base::DictionaryValue experiment_user_data = GetExperiment();
  user_data.Append(experiment_user_data);

  if (confirmation.type != ConfirmationType::kConversion) {
    callback(user_data);
    return;
  }

  database::table::ConversionQueue database_table;
  database_table.GetForCreativeInstanceId(confirmation.creative_instance_id,
      [=](const Result result,
          const ConversionQueueItemList& conversion_queue_items) {
        if (result != Result::SUCCESS) {
          BLOG(1, "Failed to get conversion queue");
          callback(user_data);
          return;
        }

        if (conversion_queue_items.empty()) {
          callback(user_data);
          return;
        }

        ConversionQueueItemInfo conversion_queue_item =
            conversion_queue_items.front();

        const base::DictionaryValue conversion_user_data =
            GetConversion(conversion_queue_item);

        user_data.Append(conversion_user_data);

        callback(user_data);
      });
}

}  // namespace user_data
}  // namespace dto
}  // namespace ads
