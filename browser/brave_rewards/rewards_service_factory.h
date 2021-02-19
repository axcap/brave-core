/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_BRAVE_REWARDS_REWARDS_SERVICE_FACTORY_H_
#define BRAVE_BROWSER_BRAVE_REWARDS_REWARDS_SERVICE_FACTORY_H_

#include "base/memory/singleton.h"
#include "base/scoped_observation.h"
#include "brave/components/brave_rewards/browser/rewards_service.h"
#include "chrome/browser/profiles/profile_manager_observer.h"
#include "chrome/browser/profiles/profile_manager.h"
#include "components/keyed_service/content/browser_context_keyed_service_factory.h"

class Profile;

namespace brave_rewards {
class RewardsService;

// Singleton that owns all RewardsService and associates them with Profiles.
class RewardsServiceFactory : public BrowserContextKeyedServiceFactory,
                              public ProfileManagerObserver {
 public:
  RewardsServiceFactory(const RewardsServiceFactory&) = delete;
  RewardsServiceFactory& operator=(const RewardsServiceFactory&) = delete;

  static brave_rewards::RewardsService* GetForProfile(Profile* profile);

  static RewardsServiceFactory* GetInstance();

  static void SetServiceForTesting(RewardsService* service);

 private:
  friend struct base::DefaultSingletonTraits<RewardsServiceFactory>;

  RewardsServiceFactory();
  ~RewardsServiceFactory() override;

  // BrowserContextKeyedServiceFactory:
  KeyedService* BuildServiceInstanceFor(
      content::BrowserContext* context) const override;
  bool ServiceIsNULLWhileTesting() const override;

  // ProfileManagerObserver:
  void OnProfileAdded(Profile* profile) override;

  base::ScopedObservation<ProfileManager, ProfileManagerObserver>
      profile_manager_observer_{this};
};

}  // namespace brave_rewards

#endif  // BRAVE_BROWSER_BRAVE_REWARDS_REWARDS_SERVICE_FACTORY_H_
