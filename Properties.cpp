#include "Properties.h"


/// <summary>
/// This method starts an outbreak by selecting an individual randomly
/// from a random facility. Movement around the network will then cause more infections.
/// Probabilities are specified in the code.
/// </summary>
void GraphProperties::RunSimulation(GraphType& graph, TransferLevel level, int average_duration, std::string file_name, int days)
{
	Instrumentor::Get().BeginSession("RunSimulation");
	{
		InstrumentationTimer timer("RunSimulation scope");

		// Output summary statistics to a csv file
		std::ofstream file;
		file.open(file_name);

		file << "Day" << "," << "Facility Number" << "," << "Unique ID" << "," << "Role" << "," << "Infected Status" << "," << "Infected Duration" << "\n";


		for (int day = 0; day < days; day++)
		{
			// for each vertex in the graph.
			auto vpair = vertices(graph);
			for (auto iter = vpair.first; iter != vpair.second; iter++)
			{
				NursingHome facility = get(&VertexProperties::facility, graph)[*iter];

				//			/*for (int i = 0; i < Constants::numOfResidents; i++)
				//			{
				//				for (int j = 0; j < Constants::numOfResidents; i++)
				//				{
				//					if (i == j)
				//						facility.res_res[i][j] = 1;
				//				}
				//			}

				//			for (int i = 0; i < Constants::numOfWorkers; i++)
				//			{
				//				for (int j = 0; j < Constants::numOfWorkers; j++)
				//				{
				//					if (i == j)
				//						facility.wor_wor[i][j] = 1;
				//				}
				//			}*/


				// If a transfer needs to take place between two facilities, do that here.




				// Check the number of infections for this day. Do any need to end?




				// Write the worker's info for today into the output file. Note: workers is a vector of pointers,
				// so we use the arrow operator to dereference the pointer and call the Person class methods.
				for (Worker* var : facility.workers)
				{
					file << day + 1 << "," << *iter + 1 << "," << var->GetID() << "," << "Worker" << "," << var->GetStatus() << "," << var->GetDuration() << "\n";
				}

				// Write the resident's info for today into the output file. Note: residents is a vector of pointers,
				// so we use the arrow operator to dereference the pointer and call the Person class methods.
				for (Resident* var : facility.residents)
				{
					file << day + 1 << "," << *iter + 1 << "," << var->GetID() << "," << "Resident" << "," << var->GetStatus() << "," << var->GetDuration() << "\n";
				}
			}

			// Another way to iterate over the graph:
			/*for (auto vd : boost::make_iterator_range(vertices(graph)))
			{
				NursingHome facility = graph[vd].facility;
			}*/

		}

		file.close();

	}
	Instrumentor::Get().EndSession();
}
