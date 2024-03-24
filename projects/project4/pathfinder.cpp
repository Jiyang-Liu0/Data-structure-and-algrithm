#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "list.hpp"
#include "queue.hpp"
#include "problem.hpp"
#include <set>

State breadth_first_search(Problem<Pixel> problem)
{
  State init_state = problem.initial();
  if (problem.goal(init_state))
  {
    return init_state;
  }

  Queue<State,List<State>> frontier;
  std::set<State> frontier_set;

  frontier.enqueue(init_state);
  frontier_set.insert(init_state);

  std::set<State> explored;

  while (true)
  {
    if (frontier.isEmpty())
    {
      throw std::logic_error("No goal pixel.");
    }

    State s = frontier.peekFront();
    if(problem.goal(s))
    {
      return s;
    }

    explored.insert(s);
    frontier.dequeue();
    frontier_set.erase(s);

    for (State s_next : problem.actions(s))
    {
      auto it_exp = explored.find(s_next);
      auto it_fron = frontier_set.find(s_next);
      if (it_exp == explored.end() && it_fron == frontier_set.end())
      {
        frontier.enqueue(s_next);
        frontier_set.insert(s_next);
      }
    }
  }
}


int main(int argc, char *argv[])
{
  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: pathfinder "
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  // Read input image from file
  Image<Pixel> image = readFromFile(input_file);

  Problem<Pixel> problem(image);
  if (!problem.isValid())
  {
    std::cerr << "Error:Image is invalid" << std::endl;
    return EXIT_FAILURE;
  }

  try
  {
    State solution = breadth_first_search(problem);
    image(solution.row_idx,solution.col_idx) = GREEN;
  }
  catch(const std::logic_error& e)
  {
    writeToFile(image, output_file);
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }

  // Write solution image to file
  writeToFile(image, output_file);
  return EXIT_SUCCESS;
}
