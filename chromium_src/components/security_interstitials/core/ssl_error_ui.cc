/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "components/security_interstitials/core/ssl_error_ui.h"

#define HandleCommand HandleCommand_ChromiumImpl
#include "../../../../../components/security_interstitials/core/ssl_error_ui.cc"
#undef HandleCommand

namespace security_interstitials {

void SSLErrorUI::HandleCommand(SecurityInterstitialCommand command) {
  if (command == CMD_OPEN_HELP_CENTER) {
    controller_->metrics_helper()->RecordUserInteraction(
        security_interstitials::MetricsHelper::SHOW_LEARN_MORE);

    // For now redirect everything to the base support URL.
    controller_->OpenUrlInNewForegroundTab(controller_->GetBaseHelpCenterUrl());
    return;
  }

  HandleCommand_ChromiumImpl(command);
}

}  // namespace security_interstitials
