/* This Source Code Form is subject to the terms of the Mozilla Public
 * License. v. 2.0. If a copy of the MPL was not distributed with this file.
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

const currencyNames = {
  'BTC': 'Bitcoin',
  'ETH': 'Ethereum',
  'LTC': 'Litecoin',
  'BCH': 'Bitcoin Cash',
  'ZEC': 'ZEC',
  'OXT': 'OXT',
  'BAT': 'BAT',
  'LINK': 'Chainlink',
  'DAI': 'DAI',
  'CRO': 'Crypto.com'
}

const links = {
  'buyTop': 'https://auth.crypto.com/exchange/signup?utm_source=Brave&utm_medium=Trading%20Widget&utm_campaign=Brave%3AWW-en%3ATrading-Widget_MVP_InitialWidgetState_BuyButton_Top&utm_content=MVP_InitialWidgetState_BuyButton_Top',
  'buyBottom': 'https://auth.crypto.com/exchange/signup?utm_source=Brave&utm_medium=Trading%20Widget&utm_campaign=Brave%3AWW-en%3ATrading-Widget_MVP_InitialWidgetState_BuyButton_Bottom&utm_content=MVP_InitialWidgetState_BuyButton_Bottom'
}

const dynamicBuyLink = (pair: string) => {
  return `https://auth.crypto.com/exchange/signup?utm_source=Brave&utm_medium=Trading-Widget&utm_campaign=Brave:WW-en:Trading-Widget_MVP_CryptoDetails_${pair}&utm_content=MVP_CryptoDetails_${pair}`
}

export {
  currencyNames,
  dynamicBuyLink,
  links
}
