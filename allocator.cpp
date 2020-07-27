#include "allocator.hpp"

int lightning::Allocator::freeblock = 0;
std::bitset<1024> lightning::Allocator::bufmap = std::bitset<1024>();
char lightning::Allocator::buffer[2048];
