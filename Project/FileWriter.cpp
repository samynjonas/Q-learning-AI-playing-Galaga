#include "FileWriter.h"
#include <iostream>
#include <fstream>
#include <sstream>

FileWriter::FileWriter(std::string filepath)
	: FILEPATH{ filepath }
{

}

FileWriter::~FileWriter()
{

}

void FileWriter::Write(int episodeNum, std::vector<Connection*> m_VecConnections)
{
	std::ofstream output{ FILEPATH + "\\Episode_" + its(episodeNum) + ".txt" };
	//std::ofstream output{ FILEPATH + ".txt" };

	//Episode
	output << "<NeuralNetwork" << std::endl;

	output << "\tepisode=\"" << its(episodeNum) << "\"" << std::endl;
	output << "\tscore=\"" << its(GAME_ENGINE->GetGameScore()) << "\"" << std::endl;
	
	output << "/>" << std::endl << std::endl;

	//Weigth
	for (int index{}; index < m_VecConnections.size(); index++)
	{
		output << "<";
		output << "Connection " << its(index + 1) << std::endl;
		for (const auto& weight : m_VecConnections[index]->m_VecWeights)
		{
			output << "\tweight=\"" << fts(weight->value) << "\"" << std::endl;
		}
		output << "/>" << std::endl << std::endl;

	}
	output.close();
}

std::string FileWriter::its(int intValue) const
{
	return std::to_string(intValue);
}

std::string FileWriter::fts(float floatValue) const
{
	return std::to_string(floatValue);
}