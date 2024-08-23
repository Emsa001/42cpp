/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:06:43 by escura            #+#    #+#             */
/*   Updated: 2024/08/01 21:41:09 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(std::string filename, std::string old_word, std::string new_word)
{
    this->filename = filename;
    this->old_word = old_word;
    this->new_word = new_word;
}

void Replacer::run()
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "❌ Failed to open the file: " << filename << std::endl;
        return;
    }
    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open()) {
        std::cerr << "❌ Failed to create the output file: " << filename << ".replace" << std::endl;
        return;
    }

    std::cout << "🔄 Replacing " << old_word << " with " << new_word << " in " << filename << std::endl;

    std::string line;
    while (std::getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(old_word, pos)) != std::string::npos) {
            line.erase(pos, old_word.length());
            line.insert(pos, new_word);
            pos += new_word.length();
        }
        outputFile << line << "\n";
    }

    std::cout << "✅ Finished replacing" << std::endl;

    file.close();
    outputFile.close();
}
