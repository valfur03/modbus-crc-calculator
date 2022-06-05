#include <bitset>
#include <cstddef>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	const int			reflected_polynomial = 0xA001;	// This is the CRC polynomial,
														// but reflected (the starting bits at the end).
	int					CRC_register = 0xFFFF;			// The register
	const std::string	string_to_encode(argv[1]);

	const std::string::const_iterator	string_end = string_to_encode.end();
	for (std::string::const_iterator it = string_to_encode.begin(); it != string_end; ++it)
	{
		CRC_register ^= *it;
		for (size_t i = 0; i < 8; i++)
		{
			const short int LSB = CRC_register & 1; // Extract the Least Significant Bit
			CRC_register >>= 1;
			if (LSB == 1)
				CRC_register ^= reflected_polynomial;
		}
	}
	std::cout << std::bitset<16>(CRC_register) << std::endl;
	return 0;
}
