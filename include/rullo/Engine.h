#ifndef RULLO_ENGINE_H
#define RULLO_ENGINE_H

#include <string>
#include <boost/utility.hpp>

namespace rullo {
    class Engine : boost::noncopyable {
    public:
        Engine();        
        ~Engine();
        void importRule(const std::string& iFileName);
        unsigned id() const {
            return id_;
        }
    private:
        static unsigned GetId();
        static unsigned CurrentId;
        unsigned id_;
    };
}

#endif
