#ifndef SERVICE_MANAGER_HPP
# define SERVICE_MANAGER_HPP

#include "Service.hpp"

typedef enum service_state {
	ACTIVE,
	INACTIVE,
	RELOADING,
	FAILED,
	ACTIVATING,
	DEACTIVATING
};

class ServiceManager {
	private:
		std::set<std::tuple<unsigned int, Service, service_state>> service_set;
	public:
		ServiceManager(void);
		bool isTemplateInstalled(void);
		// Service operations
		bool createNewService(std::string service_name);
		bool startService(Service service);
		bool stopService(Service service);
		bool startServices(std::vector<unsigned int> services);
		bool stopServices(std::vector<unsigned int> services);
		bool deleteService(Service service);
		bool deleteServices(std::vector<unsigned int> services);
		//Getter
		const Service getService(unsigned int id);
};

#endif
