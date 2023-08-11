# An animal shelter that houses cats and dogs wants to ensure no pet has to wait too long for a forever home. 
# Therefore, anyone who comes to adopt a pet can pick the species (cat or dog) but not the specific animal; 
# they are assigned the animal of that species that has been in the shelter longest. 
# If there are no animals available of the desired species, they must take the other species. 
# You are given a list of pets in the shelter with their names, species, and time in the shelter at the start of a week. 
# You receive a sequence of incoming people (to adopt pets) and animals (new additions to the shelter) one at a time. 
# Print the names and species of the pets as they are adopted out.

# Technique: Maintain two max heaps
# Approach: Maintain two max heaps, one for cats and one for dogs.
# When a new animal is added, add it to the appropriate heap.
# Heaps are used to order the animals by the time they have been in the shelter.
# When a person comes to adopt a pet, check which heap has the animal that has been in the shelter the longest.
# If the person wants a cat, then check if the cat heap is empty. If it is empty, then the person has to adopt a dog, and vice versa.

# Assumption: When adopting a new animal, their associated time in the shelter is 0 days.


# Time complexity: O(nlogn) where n is the number of animals in the shelter, since we are using heaps to order the animals
# Space complexity: O(n) where n is the number of animals in the shelter, since we are using heaps to store the animals
# Time taken: ~45 mins


import heapq

def adopt(pets, sequence):
    dogs, cats = [], []
    res = []

    for pet in pets:
        pet_name, species, days_str = pet.split(", ")
        days = int(days_str.split()[0])

        if species == 'dog':
            heapq.heappush(dogs, (-days, pet_name))
        else:
            heapq.heappush(cats, (-days, pet_name))
    
    for item in sequence:
        name = object = species = None
        if len(list(item)) == 3:
            name, object, species = item
        
        if species and species == 'dog' and object == 'person':
            if dogs:
                res.append((heapq.heappop(dogs)[1], species))
            else:
                res.append((heapq.heappop(cats)[1], species))
        
        elif species and species == 'cat' and object == 'person':
            if cats:
                res.append((heapq.heappop(cats)[1], species))
            else:
                res.append((heapq.heappop(dogs)[1], species))
        
        else:
            if species == 'dog':
                heapq.heappush(dogs, (0, name))
            else:
                heapq.heappush(cats, (0, name))
    
    return res


def main():
    initial_pets = [
    "Sadie, dog, 4 days",
    "Woof, cat, 7 days",
    "Chirpy, dog, 2 days",
    "Lola, dog, 1 day"
    ]

    actions = [
        ("Bob", "person", "dog"),
        ("Floofy", "cat"),
        ("Sally", "person", "cat"),
        ("Ji", "person", "cat"),
        ("Ali", "person", "cat")
    ]

    output = adopt(initial_pets, actions)
    for line in output:
        print(line)


if __name__ == "__main__":
    main()