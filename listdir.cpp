#include <boost/filesystem/operations.hpp>
#include <iostream>
#include <string>
#include <boost/property_tree/json_parser.hpp>
#include <boost/array.hpp>
#include <boost/property_tree/ptree.hpp>

using namespace std;
using namespace boost::filesystem;
using boost::property_tree::ptree;

ptree pt;
ptree children;

int main(int argc, char* argv[])
{
    if (argc == 2) {
        //char c[] = "C:/Users/Bryan/source/repos/Boost/Boost";
        path p(argv[1]);
        directory_iterator end_itr;

        for (directory_iterator itr(p); itr != end_itr; ++itr)
        {
            if (is_regular_file(itr->path())) {
                string current_file = itr->path().string();

                path p(current_file);
                int size = file_size(p);

                int i = current_file.length();
                string name;
                i = i - 1;
                char d = 92;

                for (i; i >= 0; i--) {
                    char temp = current_file[i];
                    if (temp == '/' || temp == d) {
                        for (int j = i + 1; j < current_file.length(); j++) {
                                name = name + current_file[j];
                        }
                        break;
                    }
                }

                ptree child1;

                child1.put("name", name);
                child1.put("size", size);

                children.push_back(std::make_pair("", child1));

            }
        }            
        pt.add_child("files", children);
        write_json("dir.json", pt);

        return 0;
    }
    else {
        cout << "ADD A ROUTE";
    }

}

