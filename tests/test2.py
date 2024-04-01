import asyncio

async def my_coroutine():
    loop = asyncio.get_event_loop()
    print(f"Running on event loop {loop}")

async def main():
    loop = asyncio.new_event_loop()
    asyncio.set_event_loop(loop)
    await my_coroutine()

loop = asyncio.get_event_loop()
loop.run_until_complete(main())