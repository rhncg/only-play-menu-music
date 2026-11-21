#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GameManager.hpp>

class $modify(GameManager) {
    void fadeInMusic(std::string path) {
        static const std::unordered_set<std::string> blocked = {"secretLoop.mp3", "secretLoop02.mp3", "secretLoop03.mp3", "tower01.mp3"};

        if (blocked.count(path)) {
            return;
        }

        GameManager::fadeInMusic(path);
    }
};

#include <Geode/modify/FMODAudioEngine.hpp>
class $modify(FMODAudioEngine) {
    void playMusic(std::string path, bool shouldLoop, float fadeInTime, int channel) {
        static const std::unordered_set<std::string> blocked = {"secretShop.mp3", "shop.mp3", "shop4.mp3", "shop3.ogg", "shop5.ogg"};

        if (blocked.count(path)) {
            return;
        }

        FMODAudioEngine::playMusic(path, shouldLoop, fadeInTime, channel);
    }
};