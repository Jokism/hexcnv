#include <stdio.h>
#include <iostream>
#include <bitset>
#include <sstream>
#include <bits/stdc++.h>

std::string BinaryStringToText(std::string binaryString) {
    std::string text = "";
    std::stringstream sstream(binaryString);
    while (sstream.good())
    {
        std::bitset<8> bits;
        sstream >> bits;
        text += char(bits.to_ulong());
    }
    return text;
}

int BinaryStringToDecimal(std::string const& binaryString)
{
	int ans = 0;
	
	// Initialized base value by 1 i.e. 2 to power 0.
	int base_value = 1;

	int temp = stoi(binaryString);
    
        // While temp is not equal to 0.
	while (temp) {
        
            // Grab the last digit of temp.
	    int last_digit = temp % 10;
        
            // Divide temp by 10, or essentially remove the last digit of temp.
	    temp = temp / 10;

	    ans += last_digit * base_value;

            // Multiply base_value by 2.
	    base_value = base_value * 2;
	}
	
	return ans;
}

int main(void){
    unsigned char Data = 0xff;

    char argv1[] = {'\x3C','\x33','\x8B','\x82', '\0'};
	char argv2[] = {'\x02', '\x9A', '\0'};
    char argv3[] = {'\x9A', '\x02', '\0'};
	

    //sscanf(argv1, "0x%hhx", &Data);

    //printf("data is %s\n", Data);

	for (int i =0; i < 4; i++)
	{
		printf("%02hhX ", argv1[i] & 0xff );
	}
	printf("\n");
	
	for (int i =0; i < 1; i++)
	{
		
		printf("%04X ", argv2[i] & 0xff );
	}
	printf("\n");
	
	for (int i =0; i < 2; i++)
	{
		printf("%02hhX ", argv3[i] & 0xff );
	}
	printf("\n");
	
	std::cout << std::hex << argv1 << std::dec << std::endl;
	std::cout << std::hex << argv2 << std::dec << std::endl;
	std::cout << std::hex << argv3 << std::dec << std::endl;
	std::cout << "1010011010" << std::endl;
	
	std::string binaryString = "1010011010";
    std::cout << "Binary string: " << binaryString << "!\n";
    std::cout << "Result binary string to text: " << BinaryStringToText(binaryString) << "!\n";
	std::cout << "Result binary string to decimal: " << BinaryStringToDecimal(binaryString) << "!\n";
	std::string binaryString2 = binaryString;
	std::reverse(binaryString.begin(), binaryString.end());
    std::cout << "Binary string: " << binaryString << "!\n";
    std::cout << "Result binary string to text: " << BinaryStringToText(binaryString) << "!\n";
	std::cout << "Result binary string to decimal: " << BinaryStringToDecimal(binaryString) << "!\n";

    return 0;

}