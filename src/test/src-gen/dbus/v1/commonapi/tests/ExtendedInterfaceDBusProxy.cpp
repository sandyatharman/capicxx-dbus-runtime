/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.dbus 3.1.4.v201511201313.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#include <v1/commonapi/tests/ExtendedInterfaceDBusProxy.hpp>

namespace v1 {
namespace commonapi {
namespace tests {

std::shared_ptr<CommonAPI::DBus::DBusProxy> createExtendedInterfaceDBusProxy(
	const CommonAPI::DBus::DBusAddress &_address,
	const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection) {
	return std::make_shared<ExtendedInterfaceDBusProxy>(_address, _connection);
}

INITIALIZER(registerExtendedInterfaceDBusProxy) {
     CommonAPI::DBus::Factory::get()->registerProxyCreateMethod(
		ExtendedInterface::getInterface(),
		&createExtendedInterfaceDBusProxy);
}

ExtendedInterfaceDBusProxy::ExtendedInterfaceDBusProxy(
	const CommonAPI::DBus::DBusAddress &_address,
	const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection)
	:	CommonAPI::DBus::DBusProxy(_address, _connection),
		TestInterfaceDBusProxy(_address, _connection)
{
}


    
    void ExtendedInterfaceDBusProxy::TestIntMethodExtended(const uint32_t &_inInt, CommonAPI::CallStatus &_internalCallStatus, const CommonAPI::CallInfo *_info) {
        CommonAPI::Deployable<uint32_t, CommonAPI::EmptyDeployment> deploy_inInt(_inInt, static_cast<CommonAPI::EmptyDeployment*>(nullptr));
        CommonAPI::DBus::DBusProxyHelper<
            CommonAPI::DBus::DBusSerializableArguments<
            CommonAPI::Deployable<uint32_t, CommonAPI::EmptyDeployment >
            >,
            CommonAPI::DBus::DBusSerializableArguments<
            >
        	>::callMethodWithReply(
        *this,
        "TestIntMethodExtended",
        "u",
(_info ? _info : &CommonAPI::DBus::defaultCallInfo),
deploy_inInt,
_internalCallStatus);
}
    std::future<CommonAPI::CallStatus> ExtendedInterfaceDBusProxy::TestIntMethodExtendedAsync(const uint32_t &_inInt, TestIntMethodExtendedAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
        CommonAPI::Deployable<uint32_t, CommonAPI::EmptyDeployment> deploy_inInt(_inInt, static_cast<CommonAPI::EmptyDeployment*>(nullptr));
        return CommonAPI::DBus::DBusProxyHelper<
            CommonAPI::DBus::DBusSerializableArguments<
            CommonAPI::Deployable<uint32_t, CommonAPI::EmptyDeployment >
            >,
            CommonAPI::DBus::DBusSerializableArguments<
            >
        	>::callMethodAsync(
        *this,
        "TestIntMethodExtended",
        "u",
        (_info ? _info : &CommonAPI::DBus::defaultCallInfo),
        deploy_inInt,
        [_callback] (CommonAPI::CallStatus _internalCallStatus) {
        	if (_callback)
        		_callback(_internalCallStatus);
        },
        std::make_tuple());
    }


void ExtendedInterfaceDBusProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
          ownVersionMajor = 1;
          ownVersionMinor = 0;
      }

      } // namespace tests
      } // namespace commonapi
      } // namespace v1
