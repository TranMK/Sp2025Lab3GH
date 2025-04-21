#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BinaryTree.hpp"
#include "TreeNode.hpp"

// Used an an indicator when opening a file to vary the access flags. Used in
// `utility.cpp`.
bool past_first_file = false;
template <typename T> void take_handle_user_options(BinaryTree<T>& tree);
auto main() -> int {
  std::string user_file_name;
  std::cout << "Type in the name of the file you would like information on: "
            << std::endl;
  std::cin >> user_file_name;
  BinaryTree<std::string> tree;
    std::ifstream file;
    file.open(user_file_name);
    std::string word;
    while(file>>word){
        std::transform(word.begin(), word.end(), word.begin(), ::toupper);//capitalizes word
        if(::ispunct(word.back())){
            word.pop_back();//removes periods, commas, etc. sticking to words
        }
        tree.Insert(word);
    }
    bool loop_options = true;
    while(loop_options){
      take_handle_user_options(tree);
    }
    tree.printInorder();
  return 0;
}
template <typename T> void take_handle_user_options(BinaryTree<T>& tree){
  std::vector<std::string> options = {"Find Word", "See Descending List", "See Ascending List", "Size", "Empty Tree", "Remove Word"};
  std::cout<<"Available options, enter -1 to stop: \n";
  for(int i = 0; i < options.size(); i++){
    std::cout<<i+1<<'.'<<options[i]<<"\n";
  }
  int user_input;
  std::cin>>user_input;
  switch(user_input){
    case -1://Quit
      std::exit(0);
    case 1:{//Find word
      std::cout<<"Enter word you'd like to find:";
      std::string user_input;
      std::cin>>user_input;
      std::transform(user_input.begin(), user_input.end(), user_input.begin(), ::toupper);
      TreeNode<T>* node = tree.Find(user_input);
      if(node==nullptr){
        std::cout<<"Node not found.\n";
      }else{
        std::cout<<"Node found!\n";
      }
      break;
    }
    case 2:{//See descending list
      std::vector<TreeNode<T>*> nodearr = tree.GetAllDescending();
      std::cout<<setw(15)<<"VALUE "<<"COUNT "<<"HEIGHT "<<"BALANCE FACTOR\n";
      for(TreeNode<T>* node : nodearr){
        std::cout<<setw(15)<<node->value<<"   "<<node->count<<"   "<<node->height<<"    "<<node->balancefactor<<'\n';
      }

      break;
    }
    case 3:{//See ascending list
      std::vector<TreeNode<T>*> nodearr = tree.GetAllAscending();
      std::cout<<setw(15)<<"VALUE "<<"COUNT "<<"HEIGHT "<<"BALANCE FACTOR\n";
      for(TreeNode<T>* node : nodearr){
        std::cout<<setw(15)<<node->value<<"   "<<node->count<<"   "<<node->height<<"    "<<node->balancefactor<<'\n';
      }
      break;
    }
    case 4:{//Size
      std::cout<<"Tree size: "<<tree.getSize()<<'\n';
      break;
    }
    case 5:{//Empty tree
      tree.EmptyTree();
      std::cout<<"Tree removed successfully.\n";
      break;
    }
    case 6:{//Remove word
      std::cout<<"Enter word you'd like to remove:";
      std::string user_input;
      std::cin>>user_input;
      std::transform(user_input.begin(), user_input.end(), user_input.begin(), ::toupper);
      TreeNode<T>* node = tree.Remove(user_input);
      if(node==nullptr){
        std::cout<<"Node not found.\n";
      }else{
        std::cout<<"Node removed!\n";
      }
      break;
    }
  }
  

}
