#ifndef SERVICE_MANAGER
# define SERVICE_MANAGER


// Class responsible to handle pz server as services (systemd in mind)

class Service;
class ServiceManager {
	public:
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
