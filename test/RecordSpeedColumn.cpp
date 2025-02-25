#include "../src/Reader.h"
#include "../src/MotorRecordVector.h"
#include <chrono>
#include <vector>

int main() {
	auto startTime = std::chrono::high_resolution_clock::now();
	CSVReader reader = CSVReader("test/csv/Motor_Vehicle_Collisions_-_Crashes_20250219.csv", true);	
	Records records;
	

	std::cout << "Total time to read and push records" << std::endl;
	std::vector<std::vector<std::string>> lines;
	std::string currentLine;
	while((currentLine = reader.readLine()) != "") {
		std::vector<std::string> parsedRecord = (records.parseRecord(currentLine));
		lines.push_back(parsedRecord);
	}
	auto endTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration<double>(endTime - startTime);
	std::cout << "Read time taken: " << duration.count() << " seconds" <<std::endl;

	size_t totalColumns = 29;
	MotorRecordVector motorRecordVector;
	//For each row of record, process the attributes.
	#pragma omp parallel for

	for (int j = 0; j < totalColumns; j++) {
		for (int i = 0; i < lines.size(); i++){
			recordVector[j].push_back(lines[i][j]);
		}
	} 

	auto endTime2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration<double>(endTime2 - startTime);
	auto processDuration = std::chrono::duration<double>(endTime2 - endTime);
	std::cout << "Row processing time: " << processDuration.count() << " seconds" << std::endl;
	std::cout << "Total Time taken: " << duration2.count() << " seconds" << std::endl;
}
