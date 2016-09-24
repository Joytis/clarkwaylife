//
// Created by Clark Burton Chambers on 9/24/16.
//

#include "EntityManager.hpp"

EntityManager::EntityManager() : cur_id_(0) {}

// Returns the Entity with given ID in the map.
// Retrns null pointer if it doesn't exist
Entity* EntityManager::get_entity(U32 id){
    if(entities_.find(id) != entities_.end()){
    	return entities_[id];
    } 
    else {
    	return nullptr;
    }
}

// Increments the cur_id_ and returns the result. 
U32 EntityManager::get_next_id() {
	cur_id_++;
	return cur_id_;
}

// Potentially create memory pooling for this. If we potentially
// 	have objects being craeted in mass, it woud be better to have a 
//	static array of entity memory we free and allocate ourselves. 
Entity* EntityManager::create_entity() {
	Entity* e = new Entity();
	if(e){
		e->id = get_next_id();
		return e;
	}
	else{
		return nullptr;
	}
}

void EntityManager::destroy_entity(U32 id) { 
	Entity* e = get_entity(id);
	if(e){
		for(auto& pair : e->cm){
			// Don't worry about rest of map. Deallocated anyways.
			if(pair.second) delete pair.second; 
		}
		// Delete the entity after deallocating the Components
		delete e;
		entities_.erase(entities_.find(id));
		// TODO(clark): THROW EVENT THAT LETS SYSTEM KNOW ENTITIES ARE GONE.
		//
	}
	else{
		debug(EDBG_ENMAN, "ENM: Can't delete ID that doesn't exist: %d", id);
	}
}