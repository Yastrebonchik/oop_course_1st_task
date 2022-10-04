//
// Created by alex on 03.10.22.
//

#include "PNI_Trax_sensor_Class.h"

int 	main() {
	std::string	test1 = "053F80000009011C40000000";
	std::string	test2 = "4C41A400004B3F91BCD8";
	std::string test3 = "0741A40000053F91BCD819413547AE";
	std::string	test4 = "05430D083B183F91BCD8193EDF4DE94D422869E241F8F5C341DEC28F3C594D0E";
	std::string	test5 = "05430D083B183F91BCD8193EDF4DE94F00080015BCA408C0163BFB4DAB173F80F5081BC16EA4371CC12D31271D42513D4F4A000000004B000000004C00000000";
	PNI_Trax_sensor_Class	receiver;
	void	*data;

	std::cout << "1-st package" << std::endl;
	data = stringIntoData(test1);
	receiver.receiveData(data, test1.length() / 2);
	receiver.printHeaders();
	receiver.clear();
	delete[] static_cast<unsigned char *>(data);

	std::cout << "------------------------------------------" << std::endl;

	std::cout << "2-nd package" << std::endl;
	data = stringIntoData(test2);
	receiver.receiveData(data, test2.length() / 2);
	receiver.printHeaders();
	receiver.clear();
	delete[] static_cast<unsigned char *>(data);

	std::cout << "------------------------------------------" << std::endl;

	std::cout << "3-rd package" << std::endl;
	data = stringIntoData(test3);
	receiver.receiveData(data, test3.length() / 2);
	receiver.printHeaders();
	receiver.clear();
	delete[] static_cast<unsigned char *>(data);

	std::cout << "------------------------------------------" << std::endl;

	std::cout << "4-th package" << std::endl;
	data = stringIntoData(test4);
	receiver.receiveData(data, test4.length() / 2);
	receiver.printHeaders();
	receiver.clear();
	delete[] static_cast<unsigned char *>(data);

	std::cout << "------------------------------------------" << std::endl;

	std::cout << "5-th package" << std::endl;
	data = stringIntoData(test5);
	receiver.receiveData(data, test5.length() / 2);
	receiver.printHeaders();
	receiver.clear();
	delete[] static_cast<unsigned char *>(data);

	return (0);
}
