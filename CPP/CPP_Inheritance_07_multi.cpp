#include <iostream>

using namespace std;

class USBDevice
{
public:
	USBDevice() = default;
	USBDevice(int id) : id(id){}

	auto GetID() const { return id; }
	void PlugAndPlay() {}

private:
	int id;
};

class NetworkDevice
{
public:
	NetworkDevice() = default;
	NetworkDevice(int id) : id(id) {}
	
	auto GetID() const { return id; }
	void Networking() {}

private:
	int id;
};

class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
	USBNetworkDevice(int usbID, int netID)
		: USBDevice(usbID), NetworkDevice(netID)
	{}
	USBNetworkDevice(int id)
		: USBDevice(id), NetworkDevice(id)
	{}
private:

};

int main()
{
	USBNetworkDevice device(1, 2);

	device.PlugAndPlay();
	device.Networking();

	//device.GetID();
	device.USBDevice::GetID();

	return 0;
}
