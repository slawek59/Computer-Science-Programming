// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person

    person *current = malloc(sizeof(person));

    if (current == NULL)
    {
        printf("Error\n");
        return NULL;
    }


    // If there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // TODO: Set parent pointers for current person

        current->parents[0] = parent0;
        current->parents[1] = parent1;

        // TODO: Randomly assign current person's alleles based on the alleles of their parents

        current->alleles[0] = parent0->alleles[rand() % 2];
        current->alleles[1] = parent1->alleles[rand() % 2];

    }

    // If there are no generations left to create
    else
    {
        // TODO: Set parent pointers to NULL

        current->parents[0] = NULL;
        current->parents[1] = NULL;

        // TODO: Randomly assign alleles

        current->alleles[0] = random_allele();
        current->alleles[1] = random_allele();

    }

    // TODO: Return newly created person

    return current;

    return NULL;
}
