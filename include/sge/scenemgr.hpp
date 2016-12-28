#ifndef __SGE_SCENE_MANAGER_HPP
#define __SGE_SCENE_MANAGER_HPP

#include <sge/engine-forward.hpp>
#include <sge/node.hpp>

#include <unordered_map>
#include <memory>
#include <string>

namespace sge
{
    class Scene
    {
        public:
            Scene();
            ~Scene();

            virtual void load(std::weak_ptr<Engine> engine) = 0;
            virtual void unload(std::weak_ptr<Engine> engine) = 0;

            Node *get_root_node() const;

        private:
            Node *root_node;
    };

    class SceneManager
    {
        public:
            SceneManager(std::weak_ptr<Engine> engine);
            ~SceneManager();

            void add_scene(std::string const &name, std::shared_ptr<Scene> scene);
            void switch_to_scene(std::string const &name);

            bool event_handler(SDL_Event *event);
            void process_handler(Uint32 delta);
            void draw_handler();

        private:
            std::weak_ptr<Engine> engine;
            std::shared_ptr<Scene> current_scene;

            std::unordered_map<std::string, std::shared_ptr<Scene>> scenes;
    };
}

#endif /* __SGE_SCENE_MANAGER_HPP */
