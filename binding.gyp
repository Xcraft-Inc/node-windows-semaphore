{
  "targets": [
    {
      "target_name": "CreateSemaphore",
      "sources": [
        "src/main.cc",
        "src/semaphore.cc"
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}