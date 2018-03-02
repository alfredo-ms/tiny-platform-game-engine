#ifndef __Collections_ICollections
#define __Collections_ICollections

#include <string>
#include "../core/typesdescription.hpp"
#include "../core/ibase.hpp"


namespace Collections {
    
	class ICollections : public Core::IBase {
		public:
			ICollections(){};
			virtual ~ICollections(){};

			virtual std::string getComponentID(void) const { return "Collections::ICollections"; };
			virtual std::string getFamilyID(void) const = 0;
	};

}

#endif // __Collections_ICollections