#include "action_header/Service.hpp"

Service::Service(void) {
		
	this.is_service_active = false;
};

Service::Service(unsigned int s_id, std::string s_name) {
	if (s_id == 0) {
		// S_ID 0 is reserved to unidentified services
		// Handke accordingly
	}
	this.service_id = s_id;
	this.service_name = s_name;
	this.is_service_active = false;
}

std::string Service::getServiceName(void) {
	return (this.service_name);
}

void Service::setServiceName(std::string s_name) {
	this.service_name = s_name;
}

unsigned int Service::getServiceId (void) {
	return (this.service_id);
}

void Service::setServiceId(unsigned int s_id) {
	this.service_id = s_id;
}

