//
// Created by alex on 02.10.22.
//


#include "PNI_Trax_sensor_Class.h"

unsigned char	hexToDecimal(const unsigned char array[2]) {
	unsigned char id;

	id = 0;
	if (array[0] - '0' < 10) {
		id += (array[0] - '0') * 16;
	}
	else {
		switch (array[0]) {
			case 'A':
				id += 10 * 16;
				break;
			case 'B':
				id += 11 * 16;
				break;
			case 'C':
				id += 12 * 16;
				break;
			case 'D':
				id += 13 * 16;
				break;
			case 'E':
				id += 14 * 16;
				break;
			case 'F':
				id += 15 * 16;
		}
	}
	if (array[1] - '0' < 10) {
		id += (array[1] - '0');
	}
	else {
		switch (array[1]) {
			case 'A':
				id += 10;
				break;
			case 'B':
				id += 11;
				break;
			case 'C':
				id += 12;
				break;
			case 'D':
				id += 13;
				break;
			case 'E':
				id += 14;
				break;
			case 'F':
				id += 15;
		}
	}
	return (id);
}

void	*stringIntoData(std::string	&str) {
	int	i;
	int j;
	void	*data;
	unsigned char	*array;
	unsigned char	byte[2];

	i = 0;
	j = 0;
	array = new unsigned char [str.length() / 2];
	while (i < str.length()) {
		byte[0] = str[i++];
		byte[1] = str[i++];
		array[j++] = hexToDecimal(byte);
	}
	data = static_cast<void *>(array);
	return (data);
}


void	PNI_Trax_sensor_Class::clear() {
	this->_kHeading.second = false;
	this->_kPitch.second = false;
	this->_kRoll.second = false;
	this->_kHeadingStatus.second = false;
	this->_kQuaternion.second = false;
	this->_kTemperature.second = false;
	this->_kDistortion.second = false;
	this->_kCalStatus.second = false;
	this->_kAccelX.second = false;
	this->_kAccelY.second = false;
	this->_kAccelZ.second = false;
	this->_kMagX.second = false;
	this->_kMagY.second = false;
	this->_kMagZ.second = false;
	this->_kGyroX.second = false;
	this->_kGyroY.second = false;
	this->_kGyroZ.second = false;
}

void	PNI_Trax_sensor_Class::printHeaders() const {
	if (this->_kHeading.second)
		std::cout << "kHeading = " << this->_kHeading.first << std::endl;
	if (this->_kPitch.second)
		std::cout << "kPitch = " << this->_kPitch.first << std::endl;
	if (this->_kRoll.second)
		std::cout << "kRoll = " << this->_kRoll.first << std::endl;
	if (this->_kHeadingStatus.second)
		std::cout << "kHeadingStatus = " << (int)this->_kHeadingStatus.first << std::endl;
	if (this->_kQuaternion.second) {
		std::cout << "kQuaternion: [1] = " << this->_kQuaternion.first[0];
		std::cout << "; [2] = " << this->_kQuaternion.first[1];
		std::cout << "; [3] = " << this->_kQuaternion.first[2];
		std::cout << "; [4] = " << this->_kQuaternion.first[3] << std::endl;
	}
	if (this->_kTemperature.second)
		std::cout << "kTemperature = " << this->_kTemperature.first << std::endl;
	if (this->_kDistortion.second)
		std::cout << "kDistortion = " << this->_kDistortion.first << std::endl;
	if (this->_kCalStatus.second)
		std::cout << "kDistortion = " << this->_kCalStatus.first << std::endl;
	if (this->_kAccelX.second)
		std::cout << "kAccelX = " << this->_kAccelX.first << std::endl;
	if (this->_kAccelY.second)
		std::cout << "kAccelY = " << this->_kAccelY.first << std::endl;
	if (this->_kAccelZ.second)
		std::cout << "kAccelZ = " << this->_kAccelZ.first << std::endl;
	if (this->_kMagX.second)
		std::cout << "kMagX = " << this->_kMagX.first << std::endl;
	if (this->_kMagY.second)
		std::cout << "kMagY = " << this->_kMagY.first << std::endl;
	if (this->_kMagZ.second)
		std::cout << "kMagZ = " << this->_kMagZ.first << std::endl;
	if (this->_kGyroX.second)
		std::cout << "kGyroX = " << this->_kGyroX.first << std::endl;
	if (this->_kGyroY.second)
		std::cout << "kGyroY = " << this->_kGyroY.first << std::endl;
	if (this->_kGyroZ.second)
		std::cout << "kGyroZ = " << this->_kGyroZ.first << std::endl;
}

void	PNI_Trax_sensor_Class::receiveData(void *data, unsigned int dataLen) {
	int		i;
	unsigned char	id;
	unsigned char	buffer[4];
	unsigned char	*dataPointer;

	i = 0;
	dataPointer = static_cast<unsigned char*>(data);
	while (i < dataLen) {
		id = dataPointer[i++];
		switch (id) {
			case KHEADING:
				for (int j = 0; j < 4; ++j) {
					buffer[3 - j] = dataPointer[i++];
				}
				this->_kHeading.first = *reinterpret_cast<float*>(buffer);
				this->_kHeading.second = true;
				break;
			case KPITCH:
				for (int j = 0; j < 4; ++j) {
					buffer[3 - j] = dataPointer[i++];
				}
				this->_kPitch.first = *reinterpret_cast<float*>(buffer);
				this->_kPitch.second = true;
				break;
			case KROLL:
				for (int j = 0; j < 4; ++j) {
					buffer[3 - j] = dataPointer[i++];
				}
				this->_kRoll.first = *reinterpret_cast<float*>(buffer);
				this->_kRoll.second = true;
				break;
			case KHEADINGSTATUS:
				for (int j = 0; j < 4; ++j) {
					buffer[j] = 0;
				}
				buffer[0] = dataPointer[i++];
				this->_kHeadingStatus.first = *reinterpret_cast<char *>(buffer);
				this->_kHeadingStatus.second = true;
				break;
			case KQUATERNION:
				for (int j = 0; j < 4; ++j) {
					for (int k = 0; k < 4; ++k) {
						buffer[3 - k] = dataPointer[i++];
					}
					this->_kQuaternion.first[j] = *reinterpret_cast<float *>(buffer);
					this->_kQuaternion.second = true;
				}
				break;
			case KTEMPERATURE:
				for (int j = 0; j < 4; ++j) {
					buffer[3 - j] = dataPointer[i++];
				}
				this->_kTemperature.first = *reinterpret_cast<float *>(buffer);
				this->_kTemperature.second = true;
				break;
			case KDISTORTION:
				for (int j = 0; j < 4; ++j) {
					buffer[j] = 0;
				}
				buffer[0] = dataPointer[i++];
				this->_kDistortion.first = *reinterpret_cast<bool *>(buffer);
				this->_kDistortion.second = true;
				break;
			case KCALSTATUS:
				for (int j = 0; j < 4; ++j) {
					buffer[j] = 0;
				}
				buffer[0] = dataPointer[i++];
				this->_kCalStatus.first = *reinterpret_cast<bool *>(buffer);
				this->_kCalStatus.second = true;
				break;
			case KACCELX:
				for (int j = 0; j < 4; ++j) {
					buffer[3 - j] = dataPointer[i++];
				}
				this->_kAccelX.first = *reinterpret_cast<float *>(buffer);
				this->_kAccelX.second = true;
				break;
			case KACCELY:
				for (int j = 0; j < 4; ++j) {
					buffer[3 - j] = dataPointer[i++];
				}
				this->_kAccelY.first = *reinterpret_cast<float *>(buffer);
				this->_kAccelY.second = true;
				break;
			case KACCELZ:
				for (int j = 0; j < 4; ++j) {
					buffer[3 - j] = dataPointer[i++];
				}
				this->_kAccelZ.first = *reinterpret_cast<float *>(buffer);
				this->_kAccelZ.second = true;
				break;
			case KMAGX:
				for (int j = 0; j < 4; ++j) {
					buffer[3 - j] = dataPointer[i++];
				}
				this->_kMagX.first = *reinterpret_cast<float *>(buffer);
				this->_kMagX.second = true;
				break;
			case KMAGY:
				for (int j = 0; j < 4; ++j) {
					buffer[3 - j] = dataPointer[i++];
				}
				this->_kMagY.first = *reinterpret_cast<float *>(buffer);
				this->_kMagY.second = true;
				break;
			case KMAGZ:
				for (int j = 0; j < 4; ++j) {
					buffer[3 - j] = dataPointer[i++];
				}
				this->_kMagZ.first = *reinterpret_cast<float *>(buffer);
				this->_kMagZ.second = true;
				break;
			case KGYROX:
				for (int j = 0; j < 4; ++j) {
					buffer[3 - j] = dataPointer[i++];
				}
				this->_kGyroX.first = *reinterpret_cast<float *>(buffer);
				this->_kGyroX.second = true;
				break;
			case KGYROY:
				for (int j = 0; j < 4; ++j) {
					buffer[3 - j] = dataPointer[i++];
				}
				this->_kGyroY.first = *reinterpret_cast<float *>(buffer);
				this->_kGyroY.second = true;
				break;
			case KGYROZ:
				for (int j = 0; j < 4; ++j) {
					buffer[3 - j] = dataPointer[i++];
				}
				this->_kGyroZ.first = *reinterpret_cast<float *>(buffer);
				this->_kGyroZ.second = true;
				break;
			default:
				break;
		}
	}
}

PNI_Trax_sensor_Class::PNI_Trax_sensor_Class() {
	this->clear();
}


PNI_Trax_sensor_Class::~PNI_Trax_sensor_Class() {
	this->clear();
}
