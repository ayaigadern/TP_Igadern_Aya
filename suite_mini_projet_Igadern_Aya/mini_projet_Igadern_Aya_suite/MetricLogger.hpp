#ifndef METRIC_LOGGER_HPP
#define METRIC_LOGGER_HPP

#include <iostream>
#include <string>
#include <fstream>

/**
 * @brief Classe template pour journaliser les métriques de différents types d'objets
 * 
 * @tparam T Type de l'objet dont on veut journaliser les métriques
 */
template<typename T>
class MetricLogger {
public:
    /**
     * @brief Écrit les métriques de l'objet dans un flux
     * 
     * @param obj L'objet dont on veut journaliser les métriques
     * @param stream Le flux dans lequel écrire (cout, fichier, etc.)
     * @param title Un titre optionnel pour l'entrée du journal
     */
    static void logToStream(const T& obj, std::ostream& stream, const std::string& title = "") {
        if (!title.empty()) {
            stream << "=== " << title << " ===" << std::endl;
        }
        stream << obj.getMetrics() << std::endl;
    }
    
    /**
     * @brief Écrit les métriques de l'objet dans un fichier
     * 
     * @param obj L'objet dont on veut journaliser les métriques
     * @param filename Nom du fichier dans lequel écrire
     * @param title Un titre optionnel pour l'entrée du journal
     * @return true si l'opération a réussi
     * @return false si l'opération a échoué
     */
    static bool logToFile(const T& obj, const std::string& filename, const std::string& title = "") {
        std::ofstream file(filename, std::ios::out | std::ios::app);
        if (!file) {
            return false;
        }
        
        logToStream(obj, file, title);
        return true;
    }
};

#endif // METRIC_LOGGER_HPP