#ifndef RULLO_ENGINE_H
#define RULLO_ENGINE_H

#include <string>
#include <set>
#include <boost/utility.hpp>
#include <boost/shared_ptr.hpp>

namespace rullo {

    class Fact;

    class Engine : boost::noncopyable {
    public:
        Engine();        
        ~Engine();
        unsigned int addRule(const std::string& iFileName);
        void addFact(const std::string& iFileName);
        unsigned id() const {
            return id_;
        }
    private:
        static unsigned GetId();
        static unsigned CurrentId;
        unsigned id_;
        std::set< boost::shared_ptr<Fact> > facts_;
    };
}

#endif
