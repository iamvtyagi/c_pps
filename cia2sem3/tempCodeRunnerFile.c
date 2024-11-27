printf("Enter the %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&stack, value);
    }
