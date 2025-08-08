#ifndef SERVICE_HPP
# define SERVICE_HPP


class Service {
	private:
		unsigned int service_id;
		std::string service_name;
		bool is_service_active;
	public:
		Service(unsigned int s_id, std::string s_name);
		std::string getServiceName(void);
		void setServiceName(std::string s_name);
		unsigned int getServiceId(void);
		void setServiceId(unsigned int);
};

#endif
