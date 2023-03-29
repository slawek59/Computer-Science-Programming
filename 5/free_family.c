// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case

    if (p == NULL)
    {
        return;
    }

    // TODO: Free parents recursively


    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // TODO: Free child

    free(p);

    return;

}
