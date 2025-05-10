/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:14:43 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/10 21:16:31 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

void replaceAll(std::string& content, const std::string& s1, const std::string& s2) {
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream infile(filename.c_str());
    if (!infile.is_open()) {
        std::cerr << "Error: cannot open input file." << std::endl;
        return 1;
    }

    // read entire file content (including '\n') into a string
    std::ostringstream buffer;
    buffer << infile.rdbuf();
    std::string content = buffer.str();
    infile.close();

    replaceAll(content, s1, s2);

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error: cannot create output file." << std::endl;
        return 1;
    }
    
    outfile << content;
    outfile.close();

    return 0;
}