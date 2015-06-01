/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.1.v201505270851.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#include <v1_0/commonapi/tests/managed/RootInterface.hpp>
#include <v1_0/commonapi/tests/managed/RootInterfaceDBusStubAdapter.hpp>

namespace v1_0 {
namespace commonapi {
namespace tests {
namespace managed {

std::shared_ptr<CommonAPI::DBus::DBusStubAdapter> createRootInterfaceDBusStubAdapter(
                   const CommonAPI::DBus::DBusAddress &_address,
                   const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection,
                   const std::shared_ptr<CommonAPI::StubBase> &_stub) {
    return std::make_shared<RootInterfaceDBusStubAdapter>(_address, _connection, _stub);
}

INITIALIZER(registerRootInterfaceDBusStubAdapter) {
    CommonAPI::DBus::Factory::get()->registerStubAdapterCreateMethod(
    	RootInterface::getInterface(), &createRootInterfaceDBusStubAdapter);
}

RootInterfaceDBusStubAdapterInternal::~RootInterfaceDBusStubAdapterInternal() {
    deactivateManagedInstances();
    RootInterfaceDBusStubAdapterHelper::deinit();
}

void RootInterfaceDBusStubAdapterInternal::deactivateManagedInstances() {
    std::set<std::string>::iterator iter;
    std::set<std::string>::iterator iterNext;

    iter = registeredLeafInterfaceInstances.begin();
    while (iter != registeredLeafInterfaceInstances.end()) {
        iterNext = std::next(iter);

        if (deregisterManagedStubLeafInterface(*iter)) {
            iter = iterNext;
        }
        else {
            iter++;
        }
    }
    iter = registeredBranchInterfaceInstances.begin();
    while (iter != registeredBranchInterfaceInstances.end()) {
        iterNext = std::next(iter);

        if (deregisterManagedStubBranchInterface(*iter)) {
            iter = iterNext;
        }
        else {
            iter++;
        }
    }
}

const char* RootInterfaceDBusStubAdapterInternal::getMethodsDBusIntrospectionXmlData() const {
    static const std::string introspectionData =
        "<method name=\"getInterfaceVersion\">\n"
            "<arg name=\"value\" type=\"uu\" direction=\"out\" />"
        "</method>\n"
        "<method name=\"testRootMethod\">\n"
            "<arg name=\"_inInt\" type=\"i\" direction=\"in\" />\n"
            "<arg name=\"_inString\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"_error\" type=\"i\" direction=\"out\" />\n"
            "<arg name=\"_outInt\" type=\"i\" direction=\"out\" />\n"
            "<arg name=\"_outString\" type=\"s\" direction=\"out\" />\n"
        "</method>\n"

    ;
    return introspectionData.c_str();
}

CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        RootInterfaceStub,
        CommonAPI::Version
        > RootInterfaceDBusStubAdapterInternal::getRootInterfaceInterfaceVersionStubDispatcher(&RootInterfaceStub::getInterfaceVersion, "uu");



CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    RootInterfaceStub,
    std::tuple<int32_t, std::string>,
    std::tuple<RootInterface::testRootMethodError, int32_t, std::string>
    > RootInterfaceDBusStubAdapterInternal::testRootMethodStubDispatcher(&RootInterfaceStub::testRootMethod, "iis", std::tuple<int32_t, std::string, RootInterface::testRootMethodError, int32_t, std::string>());





const RootInterfaceDBusStubAdapterHelper::StubDispatcherTable& RootInterfaceDBusStubAdapterInternal::getStubDispatcherTable() {
    return stubDispatcherTable_;
}

const CommonAPI::DBus::StubAttributeTable& RootInterfaceDBusStubAdapterInternal::getStubAttributeTable() {
    return stubAttributeTable_;
}
bool RootInterfaceDBusStubAdapterInternal::registerManagedStubLeafInterface(std::shared_ptr<LeafInterfaceStub> _stub, const std::string &_instance) {
    if (registeredLeafInterfaceInstances.find(_instance) == registeredLeafInterfaceInstances.end()) {
    	std::string itsAddress = "local:commonapi.tests.managed.LeafInterface:" + _instance;
        CommonAPI::DBus::DBusAddress itsDBusAddress;
        CommonAPI::DBus::DBusAddressTranslator::get()->translate(itsAddress, itsDBusAddress);

        std::string objectPath(itsDBusAddress.getObjectPath());
        std::string adapterObjectPath(getDBusAddress().getObjectPath());

        if (objectPath.compare(0, adapterObjectPath.length(), adapterObjectPath) == 0) {
        	std::shared_ptr<CommonAPI::DBus::Factory> itsFactory = CommonAPI::DBus::Factory::get();

            auto stubAdapter = itsFactory->createDBusStubAdapter(_stub, "commonapi.tests.managed.LeafInterface", itsDBusAddress, connection_);
            bool isRegistered = itsFactory->registerManagedService(stubAdapter);
            if (isRegistered) {
                bool isExported = connection_->getDBusObjectManager()->exportManagedDBusStubAdapter(adapterObjectPath, stubAdapter);
                if (isExported) {
                    registeredLeafInterfaceInstances.insert(_instance);
                    return true;
                } else {
                    itsFactory->unregisterManagedService(itsAddress);
                }
            }
        }
    }
    return false;
}

bool RootInterfaceDBusStubAdapterInternal::deregisterManagedStubLeafInterface(const std::string &_instance) {
    std::string itsAddress = "local:commonapi.tests.managed.LeafInterface:" + _instance;
    if (registeredLeafInterfaceInstances.find(_instance) != registeredLeafInterfaceInstances.end()) {
        std::shared_ptr<CommonAPI::DBus::Factory> itsFactory = CommonAPI::DBus::Factory::get();
        std::shared_ptr<CommonAPI::DBus::DBusStubAdapter> stubAdapter
            = itsFactory->getRegisteredService(itsAddress);
        if (stubAdapter) {
            connection_->getDBusObjectManager()->unexportManagedDBusStubAdapter(
                getDBusAddress().getObjectPath(), stubAdapter);
            itsFactory->unregisterManagedService(itsAddress);
            registeredLeafInterfaceInstances.erase(_instance);
            return true;
        }
    }
    return false;
}

std::set<std::string>& RootInterfaceDBusStubAdapterInternal::getLeafInterfaceInstances() {
    return registeredLeafInterfaceInstances;
}
bool RootInterfaceDBusStubAdapterInternal::registerManagedStubBranchInterface(std::shared_ptr<BranchInterfaceStub> _stub, const std::string &_instance) {
    if (registeredBranchInterfaceInstances.find(_instance) == registeredBranchInterfaceInstances.end()) {
    	std::string itsAddress = "local:commonapi.tests.managed.BranchInterface:" + _instance;
        CommonAPI::DBus::DBusAddress itsDBusAddress;
        CommonAPI::DBus::DBusAddressTranslator::get()->translate(itsAddress, itsDBusAddress);

        std::string objectPath(itsDBusAddress.getObjectPath());
        std::string adapterObjectPath(getDBusAddress().getObjectPath());

        if (objectPath.compare(0, adapterObjectPath.length(), adapterObjectPath) == 0) {
        	std::shared_ptr<CommonAPI::DBus::Factory> itsFactory = CommonAPI::DBus::Factory::get();

            auto stubAdapter = itsFactory->createDBusStubAdapter(_stub, "commonapi.tests.managed.BranchInterface", itsDBusAddress, connection_);
            bool isRegistered = itsFactory->registerManagedService(stubAdapter);
            if (isRegistered) {
                bool isExported = connection_->getDBusObjectManager()->exportManagedDBusStubAdapter(adapterObjectPath, stubAdapter);
                if (isExported) {
                    registeredBranchInterfaceInstances.insert(_instance);
                    return true;
                } else {
                    itsFactory->unregisterManagedService(itsAddress);
                }
            }
        }
    }
    return false;
}

bool RootInterfaceDBusStubAdapterInternal::deregisterManagedStubBranchInterface(const std::string &_instance) {
    std::string itsAddress = "local:commonapi.tests.managed.BranchInterface:" + _instance;
    if (registeredBranchInterfaceInstances.find(_instance) != registeredBranchInterfaceInstances.end()) {
        std::shared_ptr<CommonAPI::DBus::Factory> itsFactory = CommonAPI::DBus::Factory::get();
        std::shared_ptr<CommonAPI::DBus::DBusStubAdapter> stubAdapter
            = itsFactory->getRegisteredService(itsAddress);
        if (stubAdapter) {
            connection_->getDBusObjectManager()->unexportManagedDBusStubAdapter(
                getDBusAddress().getObjectPath(), stubAdapter);
            itsFactory->unregisterManagedService(itsAddress);
            registeredBranchInterfaceInstances.erase(_instance);
            return true;
        }
    }
    return false;
}

std::set<std::string>& RootInterfaceDBusStubAdapterInternal::getBranchInterfaceInstances() {
    return registeredBranchInterfaceInstances;
}

RootInterfaceDBusStubAdapterInternal::RootInterfaceDBusStubAdapterInternal(
        const CommonAPI::DBus::DBusAddress &_address,
        const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub)
	: CommonAPI::DBus::DBusStubAdapter(_address, _connection,true),
      RootInterfaceDBusStubAdapterHelper(_address, _connection, std::dynamic_pointer_cast<RootInterfaceStub>(_stub), true),
      stubDispatcherTable_({
            { { "testRootMethod", "is" }, &commonapi::tests::managed::RootInterfaceDBusStubAdapterInternal::testRootMethodStubDispatcher }
            }),
        stubAttributeTable_() {

    stubDispatcherTable_.insert({ { "getInterfaceVersion", "" }, &commonapi::tests::managed::RootInterfaceDBusStubAdapterInternal::getRootInterfaceInterfaceVersionStubDispatcher });
}

const bool RootInterfaceDBusStubAdapterInternal::hasFreedesktopProperties() {
    return false;
}

} // namespace managed
} // namespace tests
} // namespace commonapi
} // namespace v1_0