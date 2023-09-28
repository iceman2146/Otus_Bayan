#include "bayan.h"

void bayan::run(const std::vector<std::string> &include_paths, const std::vector<std::string> &exclude_paths, std::size_t depth)
{
  std::vector<std::string> filenames = files_list(include_paths, exclude_paths, depth);

  for (std::string path : filenames)
  {
    std::cout << path << std::endl;
  }
}

std::vector<std::string> bayan::files_list(const std::vector<std::string> &include_paths, const std::vector<std::string> &exclude_paths, std::size_t depth)
{
  std::vector<std::string> files_list;
  for (std::string i_path : include_paths)
  {
    if (boost::filesystem::exists(i_path) && boost::filesystem::is_directory(i_path))
    {
      boost::filesystem::recursive_directory_iterator iter(i_path), end;
      while (iter != end)
      {
        if (iter.depth() > depth ||
            (boost::filesystem::is_directory(iter->path()) &&
             (std::find(exclude_paths.begin(), exclude_paths.end(), iter->path().string()) != exclude_paths.end())))
        {
          iter.disable_recursion_pending();
        }
        else
        {
          if (boost::filesystem::is_regular_file(iter->path()))
          {
            files_list.push_back(iter->path().string());
          }
        }

        boost::system::error_code ec;
        iter.increment(ec);
        if (ec)
        {
          std::cerr << "Error while accessing: " << iter->path().string() << " :: " << ec.message() << '\n';
        }
      }
    }
  }
  return files_list;
}
